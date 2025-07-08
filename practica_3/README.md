# Práctica 3 - Servicios Distribuidos con gRPC

Este proyecto implementa dos ejercicios usando gRPC:
- **Ejercicio 1:** Servicio de saludo (`SayHello`, `siguienteFecha`, `sumaDiasFecha`)
- **Ejercicio 2:** Juego de Tiro al Blanco (`dimeCentroDiana`, `disparaCanon`, `mejorDisparo`)

---

## Estructura del proyecto

```
practica_3/
├── protos/
│   ├── helloworld.proto
│   └── tiro.proto
├── greeter_server.py
├── greeter_client.py
├── greeter_client.cc
├── helloworld.pb.cc
├── helloworld.grpc.pb.cc
├── tiro_server.py
├── tiro_client.py
├── tiro_pb2.py
├── tiro_pb2_grpc.py
├── helloworld_pb2.py
├── helloworld_pb2_grpc.py
```

---

## Requisitos

- Python 3.13+
- gRPC y Protobuf para Python:
  ```bash
  pip install grpcio grpcio-tools
  ```
- g++ (para cliente en C++)
- Protobuf compiler (`protoc`) con soporte para C++:
  ```bash
  sudo dnf install protobuf-compiler grpc-compiler
  ```

---

## Compilación de archivos `.proto`

### Para Python:

```bash
python3 -m grpc_tools.protoc -I=./protos --python_out=. --grpc_python_out=. ./protos/helloworld.proto
python3 -m grpc_tools.protoc -I=./protos --python_out=. --grpc_python_out=. ./protos/tiro.proto
```

### Para C++:

```bash
protoc -I=./protos --cpp_out=. --grpc_out=. --plugin=protoc-gen-grpc=`which grpc_cpp_plugin` ./protos/helloworld.proto
```

---

## Compilación del cliente C++

```bash
g++ -std=c++17 -o greeter_client greeter_client.cc helloworld.pb.cc helloworld.grpc.pb.cc `pkg-config --cflags --libs protobuf grpc++`
```

---

## Ejecución

### Servidor y cliente Python (Ejercicio 1):

```bash
python3 greeter_server.py      # en una terminal
python3 greeter_client.py      # en otra terminal
```

### Servidor y cliente Tiro al Blanco (Ejercicio 2):

```bash
python3 tiro_server.py         # en una terminal
python3 tiro_client.py         # en otra terminal
```

### Cliente C++ (Ejercicio 1):

```bash
./greeter_client
```

---

## Notas

- El centro de la diana se genera aleatoriamente al iniciar el servidor.
- Para recompilar archivos `.proto` siempre que haya cambios, vuelve a ejecutar los comandos de compilación correspondientes.


## Ejercicio 1 -  video

https://youtu.be/v8Q5e4SNUBk