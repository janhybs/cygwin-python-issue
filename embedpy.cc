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
  
  cout << "------------------" << endl;
  
  cout << "Test: time module" << endl;
  PyRun_SimpleString("\nimport time as mod; print mod, mod.__file__"
                     "\nfor x in dir(mod):\n"
                     "\n  print '{:20s}{}'.format(x, str(getattr(mod, x, ''))[0:35])"
                     );
  
  cout << "------------------" << endl;
  
  cout << "Test: binascii module" << endl;
  PyRun_SimpleString("\nimport binascii as mod; print mod, mod.__file__"
                     "\nfor x in dir(mod):\n"
                     "\n  print '{:20s}{}'.format(x, str(getattr(mod, x, ''))[0:35])"
                     );
  
  Py_Finalize();
  return 0;
}
