#!/bin/bash

echo inside $0 1>&2
pwd 1>&2
mydir=`dirname ${0}`
echo mydir=${mydir} 1>&2
cd ${mydir}/
cat part-one.src.md part-two.src.md 
cd -