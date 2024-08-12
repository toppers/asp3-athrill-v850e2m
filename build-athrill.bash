#!/bin/bash

if [ $# -eq 1 ]
then
    echo "Cleaning athrill binary"
    if [ -d athrill-target-v850e2m/cmake-build ]
    then
        rm -rf athrill-target-v850e2m/cmake-build
    fi
    exit 0
fi

if [ -d athrill-target-v850e2m/cmake-build ]
then
    :
else
    mkdir athrill-target-v850e2m/cmake-build
fi
CURR_DIR=`pwd`
cd athrill-target-v850e2m/cmake-build
cmake ..

make timer32=true serial_fifo_enable=true vdev_disable=true enable_bt_serial=true skip_clock_bugfix=true supress_detect_error=true etrobo_optimize=true reuse_port=true

function build_device()
{
    local devname=$1
    cd ${CURR_DIR}
    cd athrill-device/device/${devname}
    export CORE_DIR=${CURR_DIR}/athrill-target-v850e2m/athrill/src
    bash build.bash
    if [ `uname` = "Darwin" ]
    then
        if [ ! -f cmake-build/lib${devname}.dylib ]
        then
            echo "ERROR: can not found lib${devname}.dylib"
            exit 1
        fi
    else
        if [ ! -f cmake-build/lib${devname}.so ]
        then
            echo "ERROR: can not found lib${devname}.so"
            exit 1
        fi
    fi
    echo "now opying lib${devname} on /usr/local/lib/hakoniwa, so please enter password:"
    sudo cp cmake-build/lib${devname}.* /usr/local/lib/hakoniwa/

    cd ${CURR_DIR}
}
build_device hakotime
build_device hakosample




./athrill-target-v850e2m/cmake-build/athrill2
if [ $? -eq 0 ]
then
    echo "OK: athrill2 is created on `pwd`/athrill2"
else
    echo "ERROR: can not create athrill2"
    exit 1
fi

exit 0