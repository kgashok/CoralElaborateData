from setuptools import setup, Extension

module = Extension(
    'factorial_module',
    sources=['factorial_module.c'],
)

setup(
    name='factorial_module',
    version='1.0',
    description='Simple factorial module implemented in C',
    ext_modules=[module],
)
