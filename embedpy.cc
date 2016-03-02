#include <Python.h>
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char *argv[]) {
  Py_SetProgramName(argv[0]);
  Py_Initialize();
  
  cout << "Python path: " << (Py_GetPath()) << endl;
  cout << "Python prefix: " << (Py_GetPrefix()) << endl;
  cout << "Python exec prefix: " << (Py_GetExecPrefix()) << endl;
  
  cout << "Test: time, ctime module" << endl;
  PyRun_SimpleString("from time import time,ctime\n"
                     "print 'Today is',ctime(time())\n");
  
  cout << "Test: decoding hex" << endl;
  PyRun_SimpleString("print '7FF80000000000007FF0000000000000'.decode('hex')");
  
  cout << "Test binascii module" << endl;
  PyRun_SimpleString("import binascii");
  
  Py_Finalize();
  return 0;
}
