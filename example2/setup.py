from setuptools import Extension, setup

setup(
    ext_modules=[
        Extension(
            name="example2.ext",
            sources=["ext.c"],
        ),
    ]
)
