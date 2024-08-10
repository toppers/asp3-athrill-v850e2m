#!/bin/bash

if [ $# -ne 1 ]
then
    echo "Usage: $0 <appname>"
    exit 1
fi
APPNAME=${1}

if [ ! -f asp3/${APPNAME}/asp ]
then
    echo "ERROR: not found asp3/${APPNAME}/asp"
    exit 1
fi

cd run
../athrill-target-v850e2m/cmake-build/athrill2 \
    -c1 -i -m memory.txt -d device_config.txt \
    ../asp3/${APPNAME}/asp
