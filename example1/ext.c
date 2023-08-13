#include <Python.h>

#include "ext.h"

static ext_c_api_t ext_api = {
    .abi_version = EXT_C_ABI_VERSION,
};

static PyModuleDef ext_module = {
    PyModuleDef_HEAD_INIT,
    .m_name = "ext",
    .m_doc = "Example module that creates an extension type.",
    .m_size = -1,
};

PyMODINIT_FUNC
PyInit_ext(void)
{
    PyObject *m;

    m = PyModule_Create(&ext_module);
    if (m == NULL) {
        return NULL;
    }

    PyObject *c_api = PyCapsule_New(&ext_api, EXT_C_API_CAPSULE_NAME, NULL);
    if (c_api == NULL) {
        Py_DECREF(m);
        return NULL;
    }

    if (PyModule_AddObject(m, EXT_C_API_ATTRIBUTE_NAME, c_api) < 0) {
        Py_DECREF(c_api);
        Py_DECREF(m);
        return NULL;
    }

    return m;
}