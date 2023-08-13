#include <Python.h>

#include <example1/ext.h>

static ext_c_api_t *ext_api;

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
    if (m == NULL)
    {
        return NULL;
    }

    ext_api = PyCapsule_Import(EXT_C_API_CAPSULE_NAME, 0);
    if (ext_api == NULL)
    {
        Py_DECREF(m);
        return NULL;
    }

    if (ext_api->abi_version != EXT_C_ABI_VERSION)
    {
        Py_DECREF(m);
        return PyErr_Format(
            "C API version mismatch: module API version is '%d', but the example.ext C API version is '%d'.",
            EXT_C_ABI_VERSION, ext_api->abi_version);
    }

    return m;
}