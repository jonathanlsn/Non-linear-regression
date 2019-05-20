#include <Python.h>//include the "Python.h" header before any other include
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <math.h>
#include <zlib.h>
#include <errno.h>
#include "def_PyC.h"
#include <iostream>
#include "forest.h"


// Name for the cpp object "capsules"
#define NAME_CAPSULE_FOREST "FOREST"


/*
// Receives a Python capsule for object A, and extracts the pointer of the C++ object
// intégrer la fonction dans le sumlist pour créer la capsule.
static A* APythonToC(PyObject* args){
	A* my_A;
	PyObject* capsule;
	if (!PyArg_ParseTuple(args, "O", &capsule)){
		return NULL;
	}
	my_A = (A*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_A);
	return my_A;
}

// Frees object A Python capsule // changer la fonction
void ACapsuleDestructor(PyObject* capsule){
	A* my_A = (A*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_A);
  delete my_A;
}
*/


static Forest* ForestPythontoC(PyObject* args){
    Forest* my_Forest; 
    PyObject* capsule; // là on prend les argumetns de la capsule pour créer la forêt
// mais on veut créer une forêt vierge donc pas d'argument. Doit-on retirer args ?
	if (!PyArg_ParseTuple(args, "O", &capsule)){
		return NULL;
	}
    my_Forest = (Forest*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_FOREST);
	return my_Forest;
}

static PyObject* FitnessTreeInForest(PyObject* self, PyObject* args){
    Forest* my_Forest;
	PyObject* capsule;
	int position;
	if (!PyArg_ParseTuple(args, "Oi", &capsule,&position)){
		return NULL;
	}
	my_Forest = (Forest*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_FOREST);
    
    return Py_BuildValue("f",my_Forest->show(position)->Fitness());
}




static PyObject* SumAsInPyList(PyObject* self, PyObject* args){
	PyListObject* listOfYs;
	PyListObject** listOfBs;
    PyObject* capsule_forest;
    Forest* my_Forest;
    if (!PyArg_ParseTuple(args, "OO", &listOfYs, &listOfBs,&capsule_forest)){
    	return NULL;
	}	

	my_Forest = (Forest*) PyCapsule_GetPointer(capsule_forest,NAME_CAPSULE_FOREST);

    int sizeY = PyList_Size((PyObject*) listOfYs);
	bool* my_Y = (bool*) malloc(sizeY*sizeof(bool));  	
	for (int y = 0; y < sizeY; y++){
		my_Y[y] = (bool) PyLong_AsLong(PyList_GetItem( (PyObject*) listOfYs, (Py_ssize_t) y));
		std::cout << my_Y[y] << std::endl;
	}
	std::cout << "\n" << std::endl;
    int size2 = PyList_Size((PyObject*) listOfBs);
	bool** my_B = (bool**) malloc(size2*sizeof(bool*));  
    
	for (int i = 0; i < size2; i++){
		PyListObject* listOfAs = (PyListObject*) PyList_GetItem( (PyObject*) listOfBs, (Py_ssize_t) i);
		int size = PyList_Size((PyObject*) listOfAs);
		bool* my_A = (bool*) malloc(size*sizeof(bool));  
		my_B[i] = my_A;
	    for (int j = 0; j < size; j++){ 
			my_A[j] = (bool) PyLong_AsLong(PyList_GetItem( (PyObject*) listOfAs, (Py_ssize_t) j));
			std::cout << my_A[j] << std::endl;
		}	
		std::cout << "\n" << std::endl;
   
	}
    

	for (int i = 0; i < size2; i++){
		free(my_B[i]);	
	}
    free (my_Y);
    free (my_B); 

  	return Py_None;
}


static PyMethodDef module_funcs[] = {
    {"sum_list_As", (PyCFunction)SumAsInPyList, METH_VARARGS, "Sum the As in a list\n\nArgs:\n\tlist_As (list): list of capsules A\n\nReturns:\n\t Capsules: Object A capsule\n\t int: sum of A's a"},
	{"initiate_Forest" ,(PyCFunction)ForestPythontoC, METH_VARARGS},//METH_NOARGS ?
	{"show_Fitness_Tree",(PyCFunction)FitnessTreeInForest,METH_VARARGS},
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

