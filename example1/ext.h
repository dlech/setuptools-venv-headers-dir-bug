#include <Python.h>

#define EXT_C_API_ATTRIBUTE_NAME "_c_api"
#define EXT_C_API_CAPSULE_NAME "example1.ext." EXT_C_API_ATTRIBUTE_NAME
#define EXT_C_ABI_VERSION 1

typedef struct {
    int abi_version;
} ext_c_api_t;

