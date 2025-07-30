FROM fedora:42

# Instalar herramientas de compilación
RUN dnf install -y gcc make

# Crear directorio de trabajo y copiar el proyecto
WORKDIR /app
COPY . .

# Compilar
RUN make clean && make

# Ejecutar suma_tmk por defecto
CMD ["./suma_tmk"]
