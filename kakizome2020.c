#define PY_SSIZE_T_CLEAN
#include <Python.h>


static int kakizome2020_exec(PyObject *module) {
    int ret = -1;
    PyObject *printfunc = NULL;
    PyObject *u = NULL;

    PyObject *builtins = PyEval_GetBuiltins();
    if (builtins == NULL) { goto cleanup; }
    if ((printfunc = PyMapping_GetItemString(builtins, "print")) == NULL) { goto cleanup; }

    Py_UCS2 data[] = {0x4e00, 0x5fc3, 0x4e0d, 0x4e71};
    if ((u = PyUnicode_FromKindAndData(PyUnicode_2BYTE_KIND, data, sizeof(data) / sizeof(data[0]))) == NULL) { goto cleanup; }
    PyObject *printret = PyObject_CallFunction(printfunc, "O", u);
    if (printret == NULL) { goto cleanup; }
    Py_DECREF(printret);

    ret = 0;
cleanup:
    Py_XDECREF(printfunc);
    Py_XDECREF(u);
    if (ret != 0) {
        Py_XDECREF(module);
    }
    return ret;
}


static PyModuleDef_Slot kakizome2020_slots[] = {
    {Py_mod_exec, kakizome2020_exec},
    {0, NULL},
};


static struct PyModuleDef kakizome2020_module = {
    PyModuleDef_HEAD_INIT,
    .m_name="kakizome2020",
    .m_slots=kakizome2020_slots,
};


PyMODINIT_FUNC PyInit_kakizome2020(void) {
    return PyModuleDef_Init(&kakizome2020_module);
}
