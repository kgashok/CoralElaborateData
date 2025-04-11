#define PY_SSIZE_T_CLEAN
#include <Python.h>

/* C implementation of factorial */
static long
fact(long n) {
    return (n <= 1) ? 1 : n * fact(n - 1);
}

/* Python wrapper for fact() */
static PyObject *
py_fact(PyObject *self, PyObject *args)
{
    long n;
    if (!PyArg_ParseTuple(args, "l", &n))
        return NULL;
    if (n < 0) {
        PyErr_SetString(PyExc_ValueError, "n must be >= 0");
        return NULL;
    }
    long result = fact(n);
    return PyLong_FromLong(result);
}

/* Method table */
static PyMethodDef FactorialMethods[] = {
    {"factorial", py_fact, METH_VARARGS, "Compute n! recursively."},
    {NULL, NULL, 0, NULL}
};

/* Module definition */
static struct PyModuleDef factorialmodule = {
    PyModuleDef_HEAD_INIT,
    "factorial_module",   /* name of module */
    "A module that computes factorial.", /* module doc */
    -1,
    FactorialMethods
};

/* Module initialization */
PyMODINIT_FUNC
PyInit_factorial_module(void)
{
    return PyModule_Create(&factorialmodule);
}
