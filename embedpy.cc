#include <Python.h>
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char *argv[]) {
  Py_SetProgramName(argv[0]);  /* optional but recommended */
  Py_Initialize();
  
  cout << "Python path: " << (Py_GetPath()) << endl;
  cout << "Python prefix: " << (Py_GetPrefix()) << endl;
  cout << "Python exec prefix: " << (Py_GetExecPrefix()) << endl;
  
  cout << "Time test" << endl;
  PyRun_SimpleString("from time import time,ctime\n"
                     "print 'Today is',ctime(time())\n");
  
  cout << "binascii test 1" << endl;
  PyRun_SimpleString("print '7FF80000000000007FF0000000000000'.decode('hex')");
  
  cout << "binascii test 2" << endl;
  PyRun_SimpleString("import binascii");
  
  Py_Finalize();
  return 0;
}

/*

gcc -c $(python2.7-config --cflags) embedpy.cc
gcc embedpy.o $(/usr/bin/python2.7-config --ldflags) -o embedpy

gcc -c $(python2.7-config --cflags) -lstdc++ embedpy.cc && gcc embedpy.o $(/usr/bin/python2.7-config --ldflags) -lstdc++ -o embedpy && ./embedpy
*/