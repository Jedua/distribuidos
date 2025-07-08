import grpc
import math
import tiro_pb2
import tiro_pb2_grpc
from google.protobuf.empty_pb2 import Empty

def run():
    with grpc.insecure_channel('localhost:50052') as channel:
        stub = tiro_pb2_grpc.TiroAlBlancoStub(channel)

        # Obtener el centro
        centro_response = stub.dimeCentroDiana(Empty())
        centro = centro_response.valor
        print(f"[Cliente] Centro de la diana: {centro:.2f} m")

        for i in range(5):
            angulo = math.radians(30 + i * 5)
            velocidad = 30 + i * 5

            request = tiro_pb2.DisparoRequest(
                nombre=f"jugador{i+1}",
                angulo=angulo,
                velocidad=velocidad
            )

            response = stub.disparaCanon(request)
            print(f"[Disparo {i+1}] Distancia al centro: {response.distancia:.2f} m")

            if abs(response.distancia) <= 1:
                print("¡Disparo acertado al centro!")
                break

        # Mostrar mejor disparo
        mejor = stub.mejorDisparo(Empty())
        print(f"\n[Mejor Disparo] Jugador: {mejor.nombre}, Error: {mejor.distancia:.2f} m")


if __name__ == '__main__':
    run()
