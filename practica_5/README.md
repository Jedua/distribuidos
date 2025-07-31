# Práctica: TreadMarks Distribuido con Docker

Este proyecto demuestra una implementación básica de TreadMarks distribuido, que incluye sincronización, exclusión mutua y distribución de estructuras de datos entre procesos usando sockets TCP y Docker.

---

## 🚀 Requisitos

- Docker instalado
- Docker Compose instalado
- Fedora 42 (o entorno compatible)
- Acceso a terminal / consola

---

## 📦 Instrucciones de ejecución

1. Clona este repositorio o colócate en la carpeta raíz del proyecto:
   ```bash
   cd ~/proyectos/distribuidos/practica_5

2. Ejecuta los siguientes comandos en orden:

   ```bash
- docker-compose down        # Elimina contenedores previos
- docker-compose build       # Compila el proyecto en los contenedores
- docker-compose up          # Inicia la ejecución distribuida


3. Al finalizar la ejecución, verás en consola los mensajes de los nodos y la suma total calculada distribuida por los procesos.