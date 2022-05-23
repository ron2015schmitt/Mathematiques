#!/bin/bash

DIR=`dirname $0`
source ${DIR}/style.bash || exit 1

EXEC=$*

# echo $#
# [[ $# -lt 1 ]] && echo "nope" && exit 0;

echo -e "${BLUE}${BOLD}Creating run file${DEFCLR}${NORMAL}: ${EXEC}" 
\rm -f run
echo '# ****  This was created by the command "make run" and will be deleted upon "make cleanall" ******************' > run
for name in ${EXEC}
do
    printf "./$name  && " >> run
done
echo "echo -e \"${BLUE}${BOLD}All executables in `pwd` ran succesfully${DEFCLR}${NORMAL}\"" >> run
chmod a+rx run
chmod a-w run
