#include <Python.h>//include the "Python.h" header before any other include
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <zlib.h>
#include <errno.h>
#include "def_PyC.h"
#include "A.h"


// Name for the cpp object "capsules"
#define NAME_CAPSULE_A "A"
#define NAME_CAPSULE_B "B"

//////////////////////////////////////////////////////////////////////////////////////////////////
/*
static bool** MatricePythonToC(PyObject* args){
	bool** my_matrice = new bool*[n];
	PyObject* capsule;
	if (!PyArg_ParseTuple(args, "O", &capsule)){
		return NULL;
	}
	my_matrice = (bool**) PyCapsule_GetPointer(capsule,NAME_CAPSULE_Matrice);
	return my_matrice;
}

void MatriceCapsuleDestructor(PyObject* capsule){
	bool** my_matrice = (bool**) PyCapsule_GetPointer(capsule,NAME_CAPSULE_A);
  delete my_matrice;
}
*/

/////////////////////////////////////////////////////////////////////////////////////////////////

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

// Frees object A Python capsule
void ACapsuleDestructor(PyObject* capsule){
	A* my_A = (A*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_A);
  delete my_A;
}

// Receive and parse parameters, constructs an object A, encapsulate it and return the capsule
static PyObject* ATranslator(PyObject* self, PyObject* args){
	bool a;
	if (!PyArg_ParseTuple(args, "p", &a)){
		return NULL;
	}
	A* my_A = new A(a);
	PyObject* capsule = PyCapsule_New(my_A, NAME_CAPSULE_A, ACapsuleDestructor);
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

// Calls the Print function of object A
static PyObject*  PrintA(PyObject* self, PyObject* args){
    A*  my_A = APythonToC(args);
    my_A->Print();
    Py_INCREF(Py_None);
    return Py_None;
}


static PyMethodDef module_funcs[] = {
    {"generate_A", (PyCFunction)ATranslator, METH_VARARGS, "Create an instance of class A\n\nArgs:\n\ta (int): the parameter\n\nReturns:\n\t capsule: Object A capsule"},
    {"sum_list_As", (PyCFunction)SumAsInPyList, METH_VARARGS, "Sum the As in a list\n\nArgs:\n\tlist_As (list): list of capsules A\n\nReturns:\n\t Capsules: Object A capsule\n\t int: sum of A's a"},
    {"print_A", PrintA, METH_VARARGS,  "Print class A instance\n\n Args:\n\t capsuleA (Capsule) : object A capsule"},
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

