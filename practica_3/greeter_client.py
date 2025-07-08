import grpc
import helloworld_pb2
import helloworld_pb2_grpc

def run():
    with grpc.insecure_channel('localhost:50051') as channel:
        stub = helloworld_pb2_grpc.GreeterStub(channel)

        response = stub.SayHello(helloworld_pb2.HelloRequest(name="Jedua"))
        print("Greeter responded:", response.message)

        response = stub.SayHelloAgain(helloworld_pb2.HelloRequest(name="Jedua"))
        print("Greeter again responded:", response.message)

        hoy = helloworld_pb2.Fecha(dia=7, mes=7, anio=2025)
        siguiente = stub.siguienteFecha(hoy)
        print(f"Siguiente día: {siguiente.dia}/{siguiente.mes}/{siguiente.anio}")

        suma_request = helloworld_pb2.SumaFechaRequest(fecha=hoy, dias=10)
        nueva_fecha = stub.sumaDiasFecha(suma_request)
        print(f"Fecha +10 días: {nueva_fecha.dia}/{nueva_fecha.mes}/{nueva_fecha.anio}")


if __name__ == '__main__':
    run()
