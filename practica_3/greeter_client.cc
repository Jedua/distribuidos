#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "helloworld.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloRequest;
using helloworld::HelloReply;
using helloworld::Fecha;
using helloworld::SumaFechaRequest;

class GreeterClient {
public:
    GreeterClient(std::shared_ptr<Channel> channel)
        : stub_(Greeter::NewStub(channel)) {}

    void SayHello(const std::string& name) {
        HelloRequest request;
        request.set_name(name);

        HelloReply reply;
        ClientContext context;
        stub_->SayHello(&context, request, &reply);
        std::cout << "Respuesta del servidor: " << reply.message() << std::endl;
    }

    void ProbarFechas() {
        Fecha hoy;
        hoy.set_dia(7);
        hoy.set_mes(7);
        hoy.set_anio(2025);

        Fecha respuesta;
        ClientContext context1;
        stub_->siguienteFecha(&context1, hoy, &respuesta);
        std::cout << "Siguiente fecha: " << respuesta.dia() << "/"
                  << respuesta.mes() << "/" << respuesta.anio() << std::endl;

        SumaFechaRequest suma;
        suma.mutable_fecha()->CopyFrom(hoy);
        suma.set_dias(10);

        Fecha nueva;
        ClientContext context2;
        stub_->sumaDiasFecha(&context2, suma, &nueva);
        std::cout << "Fecha +10 días: " << nueva.dia() << "/"
                  << nueva.mes() << "/" << nueva.anio() << std::endl;
    }

private:
    std::unique_ptr<Greeter::Stub> stub_;
};

int main() {
    GreeterClient client(grpc::CreateChannel("localhost:50051", grpc::InsecureChannelCredentials()));
    client.SayHello("Jedua");
    client.ProbarFechas();

    return 0;
}
