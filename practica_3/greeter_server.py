import grpc
from concurrent import futures
import helloworld_pb2
import helloworld_pb2_grpc
import datetime


class Greeter(helloworld_pb2_grpc.GreeterServicer):
    def SayHello(self, request, context):
        return helloworld_pb2.HelloReply(message=f"Hello, {request.name}!")

    def SayHelloAgain(self, request, context):
        return helloworld_pb2.HelloReply(message=f"Hello again, {request.name}!")

    def siguienteFecha(self, request, context):
        fecha = datetime.date(request.anio, request.mes, request.dia)
        siguiente = fecha + datetime.timedelta(days=1)
        return helloworld_pb2.Fecha(dia=siguiente.day, mes=siguiente.month, anio=siguiente.year)

    def sumaDiasFecha(self, request, context):
        fecha = datetime.date(request.fecha.anio, request.fecha.mes, request.fecha.dia)
        nueva_fecha = fecha + datetime.timedelta(days=request.dias)
        return helloworld_pb2.Fecha(dia=nueva_fecha.day, mes=nueva_fecha.month, anio=nueva_fecha.year)


def serve():
    server = grpc.server(futures.ThreadPoolExecutor(max_workers=10))
    helloworld_pb2_grpc.add_GreeterServicer_to_server(Greeter(), server)
    server.add_insecure_port('[::]:50051')
    server.start()
    print("Servidor gRPC corriendo en puerto 50051...")
    server.wait_for_termination()


if __name__ == '__main__':
    serve()
