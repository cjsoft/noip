# coding=utf-8
from cx_Freeze import setup, Executable

setup(
    name = '为5229号作品投票',
    version = '0.0.1',
    description = '为5229号作品投票',
    executables = [Executable('a.py')]
    )