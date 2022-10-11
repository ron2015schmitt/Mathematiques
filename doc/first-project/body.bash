#!/bin/bash

# note this script dumps the resulting file to stdout
# any informative text needs to be dumped to stderr

echo inside $0 1>&2
pwd 1>&2
mydir=`dirname ${0}`
echo mydir=${mydir} 1>&2
cd ${mydir}/

TEMPLATE_FILE=template.src.md
MAKEFILE=../../examples/Makefile
TEMP_FILE=script.temp.md

python3 replace.py ${TEMPLATE_FILE} ${MAKEFILE} ${TEMP_FILE}
cat ${TEMP_FILE}

cd -