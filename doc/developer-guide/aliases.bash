# Mathematiques
alias m='cd ~/Mathematiques'
alias r='cd ~/Mathematiques && ./reconfigure && cd -'

# run this to commit changes
alias mcommit='mbld && mgit'

# this is the commit script
function mgit {
  cd ~/Mathematiques
  git add --all
  make git
  cd -
}

# This does a full rebuild (reconfigure, make, and run)
alias mbld='cd ~/Mathematiques  &&  ./reconfigure  &&  make all  &&  make run  &&  cd -'

function remake {
  filename="${1%.*}"  # remove the (last) extension, just in case user made a mistake
  rm -f $filename{,.o,.compiler}  && make $filename
}

function rerun {
  filename="${1%.*}"  # remove the (last) extension, just in case user made a mistake
  rm -f $filename{,.o,.compiler}  && make $filename && ./$filename
}

function redoc {
  dirname="./${1%%+(/)}" # remove any trailing slashes
  rm -f ${dirname}/body{,.o,.compiler} README.md && make ${dirname}/README.md
}

