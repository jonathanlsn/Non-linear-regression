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

// destructor
void ForestCapsuleDestructor(PyObject* capsule){
	Forest* my_Forest = (Forest*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_FOREST);
  delete my_Forest;
}

// fucntion that make the forest capsul
static PyObject* ForestTranslator(PyObject* self, PyObject* args){
	int a;
	if (!PyArg_ParseTuple(args, "h", &a)){
		return NULL;
	}
	Forest* my_Forest = new Forest(a);
	PyObject* capsule = PyCapsule_New(my_Forest, NAME_CAPSULE_FOREST, ForestCapsuleDestructor);
	return capsule;
}

//methods permiting to get the results which are in the forest object
static PyObject* nb_elmtsInForest(PyObject* self, PyObject* args){
    Forest* my_Forest;
	PyObject* capsule;
	if (!PyArg_ParseTuple(args, "O", &capsule)){
		return NULL;
	}
	my_Forest = (Forest*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_FOREST);
    
    return Py_BuildValue("i",my_Forest->nb_elmts());
}

static PyObject* FitnessTreeInForest(PyObject* self, PyObject* args){
    Forest* my_Forest;
	PyObject* capsule;
	int position;
	if (!PyArg_ParseTuple(args, "Oi", &capsule,&position)){
		return NULL;
	}
	my_Forest = (Forest*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_FOREST);

    return Py_BuildValue("i",my_Forest->showlast()->Fitness());
}

static PyObject* NbrNodeTreeInForest(PyObject* self, PyObject* args){
    Forest* my_Forest;
	PyObject* capsule;
	int position;
	if (!PyArg_ParseTuple(args, "Oi", &capsule,&position)){
		return NULL;
	}
	my_Forest = (Forest*) PyCapsule_GetPointer(capsule,NAME_CAPSULE_FOREST);
    
    return Py_BuildValue("i",my_Forest->showlast()->NbrNode());
}

// function that permit to get the matrice between the two languages
// and to solve the problem 
static PyObject* Solver(PyObject* self, PyObject* args){
	PyListObject* listOfYs;
	PyListObject** listOfBs;
    PyObject* capsule_forest;
    Forest* my_Forest;
	int nbr_generation;

    if (!PyArg_ParseTuple(args, "OOOi", &listOfBs, &listOfYs, &capsule_forest, &nbr_generation)){
    	return NULL;
	}	
	my_Forest = (Forest*) PyCapsule_GetPointer(capsule_forest,NAME_CAPSULE_FOREST);

    int sizeY = PyList_Size((PyObject*) listOfYs);
	bool* my_Y = (bool*) malloc(sizeY*sizeof(bool));  
	
	int nLignes = 0;
		
	for (int y = 0; y < sizeY; y++){
		my_Y[y] = (bool) PyLong_AsLong(PyList_GetItem( (PyObject*) listOfYs, (Py_ssize_t) y));
		nLignes +=1;
	}

    int size2 = PyList_Size((PyObject*) listOfBs);
	bool** my_X = (bool**) malloc(size2*sizeof(bool*));  
	
	int nColonnes = 1;     

	for (int i = 0; i < size2; i++){

		PyListObject* listOfAs = (PyListObject*) PyList_GetItem( (PyObject*) listOfBs, (Py_ssize_t) i);
		int size = PyList_Size((PyObject*) listOfAs);	
		bool* my_A = (bool*) malloc(size*sizeof(bool));  

		nColonnes+=1;

	    for (int j = 0; j < size; ++j){ 
	    	my_A[j] = (bool) PyLong_AsLong(PyList_GetItem( (PyObject*) listOfAs, (Py_ssize_t) j));
		}	
		my_X[i]=my_A; 
	}

	Matrix matrix_ = Matrix(my_X,my_Y,nLignes,nColonnes);
	my_Forest->generation(nbr_generation, matrix_);

	for (int i = 0; i < size2; i++){
		free(my_X[i]);	
	}
    free (my_Y);
    free (my_X); 
//free (matrix_);
  	return Py_None;
}


static PyMethodDef module_funcs[] = {
    {"solve", (PyCFunction)Solver, METH_VARARGS, "Solve the problem and gives the Best Tree and it fitness\n\nArgs:\n\tlistOfBs (list): list of Xi variables\n\tlistOfYs (list): list of Y values\n\tcapsule_forest (Capsule): forest object\n\tnbr_generation (int): nbr of loop that will make the solver to give the best tree possible \n\nReturns:\n\t Nothing"},
	{"initiate_Forest" ,(PyCFunction)ForestTranslator, METH_VARARGS,"Creat a forest capsule that will ocntain all the results\n\nArgs:\n\t"},
	{"fitnessTree",(PyCFunction)FitnessTreeInForest,METH_VARARGS},
	{"nbrTinF",(PyCFunction)nb_elmtsInForest,METH_VARARGS},
	{"nbrNinTinF",(PyCFunction)NbrNodeTreeInForest,METH_VARARGS},
	
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

