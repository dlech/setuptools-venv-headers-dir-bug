import os
import sysconfig

from setuptools import Extension, setup

INCLUDE_DIRS = (
    [
        os.path.join(
            sysconfig.get_path("data"),
            "include",
            "site",
            f"python{sysconfig.get_python_version()}",
        )
    ]
    if "VIRTUAL_ENV" in os.environ
    else None
)

setup(
    ext_modules=[
        Extension(name="example2.ext", sources=["ext.c"], include_dirs=INCLUDE_DIRS),
    ]
)
