from setuptools import Extension, setup

setup(
    headers=["ext.h"],
    ext_modules=[
        Extension(
            name="example1.ext",
            sources=["ext.c"],
        ),
    ]
)
