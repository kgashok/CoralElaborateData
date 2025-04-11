
# Factorial Module Documentation

This module provides a C implementation of factorial calculation that can be used in Python.

## Functions

### fact(long n)
**Internal C function**
- **Purpose**: Recursively calculates the factorial of a number
- **Parameters**: 
  - `n` (long): The number to calculate factorial for
- **Returns**: long - The factorial result
- **Note**: Includes a debug print statement showing calculation progress

### py_fact(PyObject *self, PyObject *args)
**Python wrapper function**
- **Purpose**: Wraps the C factorial function for Python use
- **Parameters**:
  - `self`: Standard Python object reference
  - `args`: Arguments tuple from Python
- **Returns**: PyObject* - Python long object containing result
- **Error Handling**:
  - Validates input is a valid long integer
  - Ensures n >= 0
  - Returns NULL on error

### PyInit_factorial_module()
**Module initialization function**
- **Purpose**: Initializes the Python module
- **Returns**: PyObject* - The created module
- **Implementation**: Creates module using PyModule_Create

## Module Definition
- Module Name: `factorial_module`
- Description: A module that computes factorial
- Exposed Function: `factorial` - Computes n! recursively
