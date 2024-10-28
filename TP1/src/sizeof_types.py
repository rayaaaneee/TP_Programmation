"""
sizeof_types.py

Objectif :
Fichier qui affiche la taille en octets de différents types de variables

Auteur :
Mohamed AIT EL HADJ

Date :
16/09/2024
"""

import sys

print(sys.getsizeof(int()))
print(sys.getsizeof(float()))
print(sys.getsizeof(bool()))
print(sys.getsizeof(str()))
print(sys.getsizeof(list()))
print(sys.getsizeof(tuple()))
print(sys.getsizeof(dict()))