FROM ubuntu:20.04 as athrill-v850e2m-builder

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update
RUN apt-get install -y \
	git	\
	build-essential	\
	wget	\
	gcc	\
	g++	\
	ruby	\
	vim	\
	gem \
	libssl-dev libreadline-dev zlib1g-dev \
	make	\
	autoconf \
	automake \
	pkg-config \
	curl \
	net-tools \
	netcat \
	&& apt-get clean \
	&& rm -rf /var/lib/apt/lists/*

WORKDIR /root
RUN wget https://github.com/toppers/athrill-gcc-v850e2m/releases/download/v1.1/athrill-gcc-package.tar.gz 
RUN tar xzvf athrill-gcc-package.tar.gz && \
	rm -f athrill-gcc-package.tar.gz
WORKDIR /root/athrill-gcc-package
RUN	tar xzvf athrill-gcc.tar.gz && \
	rm -f athrill-gcc-package.tar.gz && \
	rm -f *.tar.gz
WORKDIR /root/workspace
ENV PATH /root/athrill-gcc-package/usr/local/athrill-gcc/bin/:${PATH}

