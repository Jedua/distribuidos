FROM ubuntu:22.04

# Evitar preguntas interactivas
ENV DEBIAN_FRONTEND=noninteractive

# Instalar dependencias básicas
RUN apt update && apt install -y \
    curl gnupg2 lsb-release software-properties-common \
    locales sudo git vim python3-pip \
    build-essential cmake

# Configurar locales
RUN locale-gen en_US en_US.UTF-8 && update-locale LC_ALL=en_US.UTF-8 LANG=en_US.UTF-8
ENV LANG en_US.UTF-8
ENV LC_ALL en_US.UTF-8

# Añadir repositorio de ROS 2
RUN curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.asc | apt-key add -
RUN add-apt-repository universe && \
    sh -c 'echo "deb http://packages.ros.org/ros2/ubuntu $(lsb_release -cs) main" > /etc/apt/sources.list.d/ros2-latest.list'

# Instala ROS 2
RUN apt update && apt install -y ros-humble-desktop

# 👇 INSTALA rosdep
RUN apt install -y python3-rosdep

# Inicializa rosdep
RUN rosdep init && rosdep update

# Configurar entorno
RUN echo "source /opt/ros/humble/setup.bash" >> /root/.bashrc
ENV ROS_DISTRO=humble
SHELL ["/bin/bash", "-c"]

# Crear workspace
RUN mkdir -p /root/ros2_ws/src

WORKDIR /root/ros2_ws

# Instala herramientas útiles
RUN apt install -y python3-colcon-common-extensions

CMD ["bash"]
