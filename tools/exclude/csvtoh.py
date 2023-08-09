#modified from code provided by Superdisk
import sys
import csv
import ntpath
import os

flag=0
for arg in sys.argv:
    if flag:
        filename_in = arg
        break
    if arg=="-i":
        flag=1
sys.stdin = open(filename_in, 'r')

print("#ifndef __%s_h_INCLUDE" % os.path.splitext(ntpath.basename(sys.stdin.name))[0])
print("#define __%s_h_INCLUDE" % os.path.splitext(ntpath.basename(sys.stdin.name))[0])
print("extern const unsigned char %s[];" % os.path.splitext(ntpath.basename(sys.stdin.name))[0])
print("#endif")