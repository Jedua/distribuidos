import 'package:flutter/material.dart';
import 'package:grpc/grpc.dart';
import 'src/generated/uber.pbgrpc.dart';
import 'package:uber_flutter_client/src/generated/google/protobuf/empty.pb.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return const MaterialApp(
      title: 'Uber Flutter Client',
      home: UberClientScreen(),
    );
  }
}

class UberClientScreen extends StatefulWidget {
  const UberClientScreen({super.key});

  @override
  State<UberClientScreen> createState() => _UberClientScreenState();
}

class _UberClientScreenState extends State<UberClientScreen> {
  final channel = ClientChannel(
    '172.30.255.12',
    port: 50053,
    options: const ChannelOptions(credentials: ChannelCredentials.insecure()),
  );

  late final UberServiceClient stub;

  String estado = "Esperando acción...";
  int? ultimoAutoAsignado;

  @override
  void initState() {
    super.initState();
    stub = UberServiceClient(channel);
  }

  void mostrarEstadoServicio() async {
    try {
      final response = await stub.estadoServicio(Empty());
      setState(() {
        estado =
            "Total de viajes: ${response.totalViajes}\n"
            "Autos disponibles: ${response.autos.length}";
      });
    } catch (e) {
      setState(() {
        estado = "Error: $e";
      });
    }
  }

  void solicitarViaje() async {
    try {
      final posicion = Posicion(latitud: 50, longitud: 50);
      final auto = await stub.solicitarViaje(posicion);
      setState(() {
        if (auto.id == -1) {
          estado = "No hay autos disponibles.";
        } else {
          estado =
              "Auto asignado: ID=${auto.id}, "
              "distancia: ${auto.distancia.toStringAsFixed(2)}";
          ultimoAutoAsignado = auto.id;
        }
      });
    } catch (e) {
      setState(() {
        estado = "Error al solicitar viaje: $e";
      });
    }
  }

  void terminarViaje() async {
    if (ultimoAutoAsignado == null) {
      setState(() {
        estado = "Primero solicita un viaje.";
      });
      return;
    }

    try {
      final args = TerminaViajeArgs(
        idAuto: ultimoAutoAsignado!,
        posicion: Posicion(latitud: 60, longitud: 60),
      );
      final respuesta = await stub.terminarViaje(args);
      setState(() {
        estado =
            "Viaje terminado para auto ID=$ultimoAutoAsignado\n"
            "Precio final: \$${respuesta.precio.toStringAsFixed(2)}";
        ultimoAutoAsignado = null;
      });
    } catch (e) {
      setState(() {
        estado = "Error al terminar viaje: $e";
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    final bool viajeEnCurso = ultimoAutoAsignado != null;

    return Scaffold(
      appBar: AppBar(title: const Text('Cliente Uber')),
      body: Padding(
        padding: const EdgeInsets.all(24.0),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Text(
              estado,
              textAlign: TextAlign.center,
              style: const TextStyle(fontSize: 18),
            ),
            if (viajeEnCurso) ...[
              const SizedBox(height: 10),
              const Text(
                "🚗 Viaje en curso",
                style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold),
              ),
            ],
            const SizedBox(height: 30),
            ElevatedButton(
              onPressed: mostrarEstadoServicio,
              child: const Text("Estado del servicio"),
            ),
            const SizedBox(height: 10),
            ElevatedButton(
              onPressed: viajeEnCurso ? null : solicitarViaje,
              child: const Text("Solicitar viaje"),
            ),
            const SizedBox(height: 10),
            ElevatedButton(
              onPressed: viajeEnCurso ? terminarViaje : null,
              child: const Text("Terminar viaje"),
            ),
          ],
        ),
      ),
    );
  }
}
