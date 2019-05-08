#include <Python.h>//include the "Python.h" header before any other include
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <zlib.h>
#include <errno.h>
#include "def_PyC.h"
#include "Forest.h"
#include "Tree.h"
#include "Node.h"

// Name for the cpp object "capsules"
#define NAME_CAPSULE_A "Forest"
#define NAME_CAPSULE_B "Tree"

#define NAME_CAPSULE_C "Node"

// Receives a Python capsule for object A, and extracts the pointer of the C++ object
static Forest* APythonToC(PyObject* args){
	Forest* my_forest;
	PyObject* capsule;
	if (!PyArg_ParseTuple(args, "O", &capsule)){
		return NULL;
	}
	my_forest = (Forest*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_A);
	return my_forest;
}

// Receives a Python capsule for object B, and extracts the pointer of the C++ object
static Tree* BPythonToC(PyObject* args){
	Tree* my_tree;
	PyObject* capsule;
	if (!PyArg_ParseTuple(args, "O", &capsule)){
		return NULL;
	}
	my_tree = (Tree*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_B);
	return my_tree;
}

// Receives a Python capsule for object C, and extracts the pointer of the C++ object
static Node* CPythonToC(PyObject* args){
	Node* my_node;
	PyObject* capsule;
	if (!PyArg_ParseTuple(args, "O", &capsule)){
		return NULL;
	}
	my_node = (Node*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_C);
	return my_node;
}

// Frees object A Python capsule
void ACapsuleDestructor(PyObject* capsule){
	Forest* my_forest = (Forest*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_A);
  delete my_forest;
}

// Frees object B Python capsule
void BCapsuleDestructor(PyObject* capsule){
	Tree* my_tree = (Tree*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_B);
  delete my_tree;
}

// Frees object C Python capsule
void CCapsuleDestructor(PyObject* capsule){
	Node* my_node = (Node*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_C);
  delete my_node;
}

// Calls the Print function of object A
static PyObject*  PrintA(PyObject* self, PyObject* args){
    Forest*  my_forest = APythonToC(args);
    my_forest->Print();
    Py_INCREF(Py_None);
    return Py_None;
}

// Calls the Print function of object B
static PyObject*  PrintB(PyObject* self, PyObject* args){
    Tree*  my_tree = BPythonToC(args);
    my_tree->Print();
    Py_INCREF(Py_None);
    return Py_None;
}

// Calls the Print function of object C
static PyObject*  PrintC(PyObject* self, PyObject* args){
    Node*  my_node = CPythonToC(args);
    my_node->Print();
    Py_INCREF(Py_None);
    return Py_None;
}

// Receive and parse parameters, constructs an object A, encapsulate it and return the capsule
///////////A REFLECHIR/////////////
static PyObject* ATranslator(PyObject* self, PyObject* args){
	int a;
	if (!PyArg_ParseTuple(args, "h", &a)){
		return NULL;
	}
	Forest* my_forest = new Forest(a);
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
	Tree* my_tree = new Tree(b);
	PyObject* capsule = PyCapsule_New(my_tree, NAME_CAPSULE_B, BCapsuleDestructor);
	return capsule;
}

// Receive and parse parameters, constructs an object C, encapsulate it and return the capsule
static PyObject* CTranslator(PyObject* self, PyObject* args){
	int c;
  // parse the argument tuple: https://docs.python.org/3/c-api/arg.html
	if (!PyArg_ParseTuple(args, "h", &c)){
		return NULL;
	}
	Node* my_node = new Node(c);
	PyObject* capsule = PyCapsule_New(my_node, NAME_CAPSULE_C, CCapsuleDestructor);
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
		{"generate_C", (PyCFunction)CTranslator, METH_VARARGS, "Create an instance of class C\n\nArgs:\n\tc (int): the parameter\n\nReturns:\n\t capsule: Object C capsule"},
    {"sum_list_As", (PyCFunction)SumAsInPyList, METH_VARARGS, "Sum the As in a list\n\nArgs:\n\tlist_As (list): list of capsules A\n\nReturns:\n\t Capsules: Object A capsule\n\t int: sum of A's a"},
    {"print_A", PrintA, METH_VARARGS,  "Print class A instance\n\n Args:\n\t capsuleA (Capsule) : object A capsule"},
    {"print_B", PrintB, METH_VARARGS, "Print class B instance\n\n Args:\n\t capsuleB (Capsule) : object B capsule"},
    {"print_C", PrintC, METH_VARARGS,  "Print class C instance\n\n Args:\n\t capsuleC (Capsule) : object C capsule"},
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
