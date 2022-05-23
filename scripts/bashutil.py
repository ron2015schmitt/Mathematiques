#!/usr/bin/env python3

import subprocess as sp
import json


def source(filename):
    source = 'source ' + filename
    dump = '/usr/bin/python3 -c "import os;\nimport json;\nprint (json.dumps(dict(os.environ)))"'
    pipe = sp.Popen(['/bin/bash', '-c', '%s && %s' %(source,dump)], stdout=sp.PIPE)
    env = json.loads(pipe.stdout.read())
    #print(env)
    return env

def getstdout(command):
    # print(command)
    proc = sp.run(command, stdout=sp.PIPE, stderr=sp.STDOUT, shell=True)
    s = proc.stdout
    return s.decode("utf-8").strip() 

