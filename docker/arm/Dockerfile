FROM jenkins/ssh-agent:latest
RUN usermod -G plugdev jenkins && \
    apt-get update && \
    apt-get install --no-install-recommends -y \
    ca-certificates \
    gnupg \
    wget && \
    echo "deb https://archive.raspberrypi.org/debian/ bullseye main" >> /etc/apt/sources.list.d/raspi.list && \
    wget --quiet -O - http://archive.raspberrypi.org/debian/raspberrypi.gpg.key \
    | gpg --dearmor | tee /etc/apt/trusted.gpg.d/raspberrypi-archive-stable.gpg > /dev/null && \
    rm -rf /var/lib/apt/lists/*
RUN apt-get update && \
    apt-get install --no-install-recommends -y \
    binutils-arm-none-eabi \
    gcc-arm-none-eabi \
    libnewlib-arm-none-eabi \
    libnewlib-dev \
    make \
    openocd \
    python3-pip \
    usbutils && \
    rm -rf /var/lib/apt/lists/* && \
    pip install pytest siru
