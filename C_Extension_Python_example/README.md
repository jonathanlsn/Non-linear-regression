# Simple C/C++ extension module for Python

+ `setup.py` contains all the code needed to create the extension module using distutils library.
+ `install.sh` contains the command lines that should be executed to build the extension module .so:
  + Remove older .so file
  + Call the setup.py file with the `--inplace` option for `build_ext` command to put compiled .so extensions in the current folder (https://docs.python.org/2/distutils/configfile.html)
+ `script.py` a simple python script that calls the extension (simple example)
+ `my_wrapper_c.cpython-36m-darwin.so` compiled extension
+ `src` folder contains the C++/C source code
  + `A.cpp` and `A.h` : Define a simple class A
  + `B.cpp` and `B.h`: Define a simple class B
  + `def_PyC.h`: Header for a PyCapsule structure (used to encapsulate C/C++ pointers and pass them to python)
  + `main.cpp`: Simple C++ script that uses A and B (just an example, in fact this file could be removed safely)
  + `compile.sh`: Contains the command to compile `main.cpp`, so this file could also be remove safely.
  + `MyWrapper.cpp`: C++/C - Python Wrapper. This file includes the <Python.h> header, that defines functions to parse and create python objects (e.g., lists ...). The basic idea is that when a C/C++ object is created, its pointer is stored in a Capsule and returned as a python object.
  Then, if we need to apply new computations with this object we decapsulate the pointer, and run the computations. We can also return integers, floats, strs, lists ... A static PyMethodDef function (here module_funcs) is used to define the translation between the C++/C function names and their respective names in python (as well as their docstrings). The name, size, functions and docstring of the extension module are stored in a PyModuleDef struct (here moduledef). Finally, a function PyMODINIT_FUNC (here PyInit_my_wrapper_c) calls the PyModule_Create function to create the module. The name of this function should be as follows: PyInit_<name of the module as defined in setup.py>.

  ### References:

  + https://docs.python.org/3/extending/building.html
  + https://docs.python.org/3/c-api/capsule.html
