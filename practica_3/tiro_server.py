import grpc
from concurrent import futures
import math
import random
import time

import tiro_pb2
import tiro_pb2_grpc
from google.protobuf.empty_pb2 import Empty

class TiroAlBlancoServicer(tiro_pb2_grpc.TiroAlBlancoServicer):
    def __init__(self):
        self.centro_diana = random.uniform(50.0, 100.0)
        self.mejor_nombre = ""
        self.mejor_error = float("inf")

    def dimeCentroDiana(self, request, context):
        return tiro_pb2.Centro(valor=self.centro_diana)

    def disparaCanon(self, request, context):
        g = 9.81
        v = request.velocidad
        angulo = request.angulo

        d = (v * v * math.sin(2 * angulo)) / g
        error = self.centro_diana - d

        print(f"[Servidor] {request.nombre} disparó a {d:.2f} m, centro: {self.centro_diana:.2f}, error: {error:.2f}")

        if abs(error) < abs(self.mejor_error):
            self.mejor_nombre = request.nombre
            self.mejor_error = error

        return tiro_pb2.DisparoResponse(distancia=error)

    def mejorDisparo(self, request, context):
        return tiro_pb2.MejorDisparo(
            nombre=self.mejor_nombre,
            distancia=self.mejor_error
        )

def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    tiro_pb2_grpc.add_TiroAlBlancoServicer_to_server(TiroAlBlancoServicer(), server)
    server.add_insecure_port('[::]:50052')
    server.start()
    print("Servidor gRPC Tiro al Blanco iniciado en puerto 50052...")
    server.wait_for_termination()

if __name__ == '__main__':
    serve()
