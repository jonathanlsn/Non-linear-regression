#include <Python.h>//include the "Python.h" header before any other include
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <zlib.h>
#include <errno.h>
#include "def_PyC.h"
#include "A.h"
#include "B.h"

// Name for the cpp object "capsules"
#define NAME_CAPSULE_A "A"
#define NAME_CAPSULE_B "B"

// Receives a Python capsule for object A, and extracts the pointer of the C++ object
static A* APythonToC(PyObject* args){
	A* my_A;
	PyObject* capsule;
	if (!PyArg_ParseTuple(args, "O", &capsule)){
		return NULL;
	}
	my_A = (A*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_A);
	return my_A;
}

// Receives a Python capsule for object B, and extracts the pointer of the C++ object
static B* BPythonToC(PyObject* args){
	B* my_B;
	PyObject* capsule;
	if (!PyArg_ParseTuple(args, "O", &capsule)){
		return NULL;
	}
	my_B = (B*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_B);
	return my_B;
}

// Frees object A Python capsule
void ACapsuleDestructor(PyObject* capsule){
	A* my_A = (A*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_A);
  delete my_A;
}

// Frees object B Python capsule
void BCapsuleDestructor(PyObject* capsule){
	B* my_B = (B*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_B);
  delete my_B;
}

// Calls the Print function of object A
static PyObject*  PrintA(PyObject* self, PyObject* args){
    A*  my_A = APythonToC(args);
    my_A->Print();
    Py_INCREF(Py_None);
    return Py_None;
}

// Calls the Print function of object B
static PyObject*  PrintB(PyObject* self, PyObject* args){
    B*  my_B = BPythonToC(args);
    my_B->Print();
    Py_INCREF(Py_None);
    return Py_None;
}

// Receive and parse parameters, constructs an object A, encapsulate it and return the capsule
static PyObject* ATranslator(PyObject* self, PyObject* args){
	int a;
	if (!PyArg_ParseTuple(args, "h", &a)){
		return NULL;
	}
	A* my_A = new A(a);
	PyObject* capsule = PyCapsule_New(my_A, NAME_CAPSULE_A, ACapsuleDestructor);
	return capsule;
}

// Receive and parse parameters, constructs an object B, encapsulate it and return the capsule
static PyObject* BTranslator(PyObject* self, PyObject* args){
	int b;
  // parse the argument tuple: https://docs.python.org/3/c-api/arg.html
	if (!PyArg_ParseTuple(args, "h", &b)){
		return NULL;
	}
	B* my_B = new B(b);
	PyObject* capsule = PyCapsule_New(my_B, NAME_CAPSULE_B, BCapsuleDestructor);
	return capsule;
}

static PyObject* SumAsInPyList(PyObject* self, PyObject* args){
    PyListObject* listOfAs;
    int a = 0;
    if (!PyArg_ParseTuple(args, "O", &listOfAs)){
        return NULL;
    }
    int size = PyList_Size((PyObject*) listOfAs);
    for (int i = 0; i < size; i++){
        PyObject* capsule = (PyObject*) PyList_GetItem( (PyObject*) listOfAs, (Py_ssize_t) i);
        A* my_A = (A*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_A);
        a += my_A->a;
    }
    A* my_A = new A(a);
  	PyObject* capsule = PyCapsule_New(my_A, NAME_CAPSULE_A, ACapsuleDestructor);
  	return Py_BuildValue("Oi",capsule,a);
}


// Module functions {<python function name>, <function in wrapper>, <parameters flag>, <doctring>}
// https://docs.python.org/3/c-api/structures.html
static PyMethodDef module_funcs[] = {
    {"generate_A", (PyCFunction)ATranslator, METH_VARARGS, "Create an instance of class A\n\nArgs:\n\ta (int): the parameter\n\nReturns:\n\t capsule: Object A capsule"},
		{"generate_B", (PyCFunction)BTranslator, METH_VARARGS, "Create an instance of class B\n\nArgs:\n\tb (int): the parameter\n\nReturns:\n\t capsule: Object B capsule "},
    {"sum_list_As", (PyCFunction)SumAsInPyList, METH_VARARGS, "Sum the As in a list\n\nArgs:\n\tlist_As (list): list of capsules A\n\nReturns:\n\t Capsules: Object A capsule\n\t int: sum of A's a"},
    {"print_A", PrintA, METH_VARARGS,  "Print class A instance\n\n Args:\n\t capsuleA (Capsule) : object A capsule"},
    {"print_B", PrintB, METH_VARARGS, "Print class B instance\n\n Args:\n\t capsuleA (Capsule) : object B capsule"},
		{NULL, NULL, METH_NOARGS, NULL}
};

static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "my_wrapper_c",
        "my_wrapper_c module is simple example of C++ extension for python",
        sizeof(PyObject*),
				module_funcs,
				NULL,
        NULL,
        NULL,
        NULL
};

PyMODINIT_FUNC PyInit_my_wrapper_c(void){
    PyObject* module = PyModule_Create(&moduledef);
		return module;
}
