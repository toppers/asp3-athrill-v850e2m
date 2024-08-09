#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Usage: $0 <app>"
    exit 1
fi
APP_NAME=${1}

source docker/env.bash

HAKONIWA_TOP_DIR=`pwd`
IMAGE_NAME=`cat docker/image_name.txt`
IMAGE_TAG=`cat docker/latest_version.txt`
DOCKER_IMAGE=toppersjp/${IMAGE_NAME}:${IMAGE_TAG}

ARCH=`arch`
OS_TYPE=`bash docker/utils/detect_os_type.bash`
echo $ARCH
echo $OS_TYPE
if [ $OS_TYPE = "Mac" ]
then
    if [ $ARCH = "arm64" ]
    then
        docker run \
            --platform linux/amd64 \
            -v ${HOST_WORKDIR}:${DOCKER_DIR} \
            -v ${HOST_ATHRILL_DIR}:${DOCKER_ATHRILL_DIR} \
            -it --rm \
            --net host \
            -e APP_NAME=${APP_NAME} \
            --name ${IMAGE_NAME} ${DOCKER_IMAGE} \
             /bin/bash -c "cd ${APP_NAME} && make"
    else
        docker run \
            -v ${HOST_WORKDIR}:${DOCKER_DIR} \
            -v ${HOST_ATHRILL_DIR}:${DOCKER_ATHRILL_DIR} \
            -it --rm \
            --net host \
            -e APP_NAME=${APP_NAME} \
            --name ${IMAGE_NAME} ${DOCKER_IMAGE} \
             /bin/bash -c "cd ${APP_NAME} && make"
    fi
else
    docker run \
        -v ${HOST_WORKDIR}:${DOCKER_DIR} \
        -v ${HOST_ATHRILL_DIR}:${DOCKER_ATHRILL_DIR} \
        -it --rm \
        --net host \
        -e APP_NAME=${APP_NAME} \
        --name ${IMAGE_NAME} ${DOCKER_IMAGE} \
         /bin/bash -c "cd ${APP_NAME} && make"
fi
