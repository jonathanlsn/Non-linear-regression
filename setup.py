import os
os.environ["CC"] = "c++"
from distutils.core import setup, Extension
module = Extension('my_wrapper_c', ["forest.cpp","tree.cpp","node.cpp","MyWrapper.cpp","matrix.cpp"],libraries=[])
module.extra_compile_args = []#,'-pg']

setup(name='my_wrapper_c',
	  version='1.0',
	  author='Sergio Peignier',
	  author_email='sergio.peignier@insa-lyon.fr',
	  ext_modules=[module])
