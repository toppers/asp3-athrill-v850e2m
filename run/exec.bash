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
if [ `uname` = "Darwin" ]
then
    MEMORY_CONFIG="memory_mac.txt"
else
    MEMORY_CONFIG="memory_lnx.txt"
fi

../athrill-target-v850e2m/cmake-build/athrill2 \
    -c1 -i -m ${MEMORY_CONFIG} -d device_config.txt \
    ../asp3/${APPNAME}/asp
