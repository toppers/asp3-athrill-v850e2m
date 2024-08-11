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
    PROXY_CONFIG="proxy_config_mac.json"
else
    PROXY_CONFIG="proxy_config_lnx.json"
fi

hako-proxy ${PROXY_CONFIG}
