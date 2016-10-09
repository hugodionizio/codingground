#!/usr/bin/python
import sys
from os import system, chdir

if len(sys.argv) != 3:
    print "Can't run program"
    sys.exit(0)

chdir(sys.argv[1])
command = '/opt/java/jdk1.7.0_03/bin/java %s' % sys.argv[2].replace('.java','')
system(command)
