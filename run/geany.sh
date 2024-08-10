#!/bin/bash

which code > /dev/null
if [ $? -ne 0 ]
then
    echo "ERROR: can not found code, please install code command of Visual Studio Code"
    exit 1
fi

LINE_NO=`cat arg_sakura.txt | awk '{print $2}'`
FILEPATH=`cat arg_sakura.txt | awk '{print $3}'`

code -g ${FILEPATH}:${LINE_NO}
        
