import grpc
from concurrent import futures
import time
import math
import random
import threading

import uber_pb2
import uber_pb2_grpc
from google.protobuf.empty_pb2 import Empty

def calcular_distancia(pos1, pos2):
    dx = pos1.latitud - pos2.latitud
    dy = pos1.longitud - pos2.longitud
    return math.sqrt(dx**2 + dy**2)

class UberService(uber_pb2_grpc.UberServiceServicer):
    def __init__(self):
        self.autos = []
        self.total_viajes = 0
        self.inicio_viaje = {}
        self.lock = threading.Lock()  # 🔒 bloqueo para concurrencia
        self.init_autos()

    def init_autos(self):
        for i in range(8):
            auto = uber_pb2.Auto(
                id=i,
                posicion=uber_pb2.Posicion(
                    latitud=random.uniform(0, 100),
                    longitud=random.uniform(0, 100)
                ),
                disponible=True
            )
            self.autos.append(auto)
        print("[Servidor] Se inicializaron 8 autos")

    def solicitarViaje(self, request, context):
        cliente_pos = request
        mejor_auto = None
        menor_distancia = float("inf")

        with self.lock:
            for auto in self.autos:
                if auto.disponible:
                    distancia = calcular_distancia(auto.posicion, cliente_pos)
                    if distancia < menor_distancia:
                        mejor_auto = auto
                        menor_distancia = distancia

            if mejor_auto:
                mejor_auto.disponible = False
                self.inicio_viaje[mejor_auto.id] = cliente_pos  # Guarda posición inicial
                precio = menor_distancia * 10
                return uber_pb2.InfoAuto(
                    id=mejor_auto.id,
                    posicion=mejor_auto.posicion,
                    distancia=menor_distancia,
                    precio=precio
                )
            else:
                return uber_pb2.InfoAuto(id=-1, posicion=uber_pb2.Posicion(latitud=0, longitud=0), distancia=0, precio=0)

    def terminarViaje(self, request, context):
        id_auto = request.id_auto
        nueva_pos = request.posicion

        with self.lock:
            for auto in self.autos:
                if auto.id == id_auto:
                    inicio_pos = self.inicio_viaje.get(id_auto, auto.posicion)
                    distancia = calcular_distancia(inicio_pos, nueva_pos)
                    precio = distancia * 2.5
                    auto.posicion.CopyFrom(nueva_pos)
                    auto.disponible = True
                    self.total_viajes += 1
                    print(f"[Servidor] Viaje terminado por auto ID={id_auto}, distancia={distancia:.2f}, precio=${precio:.2f}")
                    self.inicio_viaje.pop(id_auto, None)
                    return uber_pb2.ResultadoViaje(precio=precio)

        return uber_pb2.ResultadoViaje(precio=0)

    def estadoServicio(self, request, context):
        with self.lock:
            disponibles = [a for a in self.autos if a.disponible]  # 👈 solo los disponibles
            print(f"[Servidor] Se solicitó el estado del servicio")
            return uber_pb2.InfoServicio(
                total_viajes=self.total_viajes,
                autos=disponibles
            )

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    uber_pb2_grpc.add_UberServiceServicer_to_server(UberService(), server)
    server.add_insecure_port('0.0.0.0:50053')
    server.start()
    print("Servidor gRPC de Uber iniciado en puerto 50053")
    server.wait_for_termination()

if __name__ == "__main__":
    serve()
# video youtube
# https://youtu.be/rtb_X-o-HsU