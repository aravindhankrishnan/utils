#!/bin/bash

GIT_FOLDER=$1
cd ${GIT_FOLDER}

NONE='\033[00m'
RED='\033[01;31m'
CYAN='\033[01;36m'
BOLD='\033[1m'
UNDERLINE='\033[4m'

while true; do
    branch_name=$(git branch | grep "*" | awk '{print $2}')
    echo -ne  "${CYAN}BRANCH${NONE} ${RED}${UNDERLINE}${branch_name}${NONE}\033[0K\r"
    sleep 1
done
