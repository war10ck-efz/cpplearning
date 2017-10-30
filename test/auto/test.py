__author__ = 'war10ck'

import os
import shlex
import sys

# demo
if __name__ == '__main__':

    f1    = open("auto.cpp", "w")
    f2    = open("int.cpp", "w")

    f1.write('#include<iostream>\n')
    f2.write('#include<iostream>\n')

    f1.write('int main(){\n')
    f2.write('int main(){\n')

    for i in range(0, 100000):
        l1 = "auto x" + str(i) + "=10;\n"
        l2 = "int x" + str(i) + "=10;\n"
        f1.write(l1)
        f2.write(l2)

    f1.write('}\n')
    f2.write('}\n')

    f1.close()
    f2.close()
