# -*- coding: utf-8 -*-

from setuptools import setup, find_packages

with open('../README.md') as f:
    readme = f.read()
with open('../LICENSE') as f:
    license = f.read()

setup(
    name='shm-py',
    version='0.1.0',
    description='sample for shared memory',
    long_description=readme,
    author='iimuz',
    author_email='hogehoge@hogehoge',
    install_requires=[],
    url='https://github.com/iimuz/ipc-samples',
    license=license,
    packages=find_packages(exclude=('tests', 'docs')),
)
