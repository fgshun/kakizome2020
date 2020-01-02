from setuptools import Extension, setup

extensions = [Extension('kakizome2020', sources=['kakizome2020.c'])]

setup(ext_modules=extensions)
