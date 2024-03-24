# Use uma imagem base do Ubuntu
FROM ubuntu:latest

# Colorize o prompt do shell (opcional)
ENV TERM=xterm-256color

# Atualize o sistema e instale as ferramentas necessárias
RUN apt-get update && \
    apt-get install -y \
        gcc \
        make \
        xorg \
        libxext-dev \
        zlib1g-dev \
        libbsd-dev \
        libglfw3-dev \
        valgrind && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Configure um usuário não privilegiado (opcional, mas recomendado para segurança)
RUN useradd -ms /bin/bash dev
USER dev
WORKDIR /home/dev

# Exponha o diretório de trabalho (opcional)
VOLUME /home/dev

# Exponha a variável de ambiente DISPLAY para suportar a interface gráfica
ENV DISPLAY=docker.for.mac.localhost:0

# Inicie um shell ao iniciar o contêiner (opcional)
CMD ["/bin/bash"]
