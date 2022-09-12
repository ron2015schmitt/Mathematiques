#!/bin/bash

echo inside $0 1>&2
pwd 1>&2
mydir=`dirname ${0}`
echo mydir=${mydir} 1>&2
cd ${mydir}/

INFO_FILE=../../versioning/config.compiler.out.txt
TEMPLATE_FILE=template.src.md
TEMP_FILE=script.temp.md

python3 replace.py ${TEMPLATE_FILE} ${INFO_FILE} ${TEMP_FILE}

cd -