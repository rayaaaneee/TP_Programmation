"""
opérateurs.py

Objectif :
Fichier qui permet de tester différentes opérations

Auteur :
Mohamed AIT EL HADJ

Date :
16/09/2024
"""

a = 16
b = 3

addition = a + b
print(f"Addition : {a} + {b} = {addition}")

soustraction = a - b
print(f"Soustraction : {a} - {b} = {soustraction}")

multiplication = a * b
print(f"Multiplication : {a} * {b} = {multiplication}")

division = a / b
print(f"Division : {a} / {b} = {division:.2f}")

modulo = a % b
print(f"Modulo : {a} % {b} = {modulo}")

egal = (a == b)
print(f"a est-il égal à b ? : {egal}")

superieur = (a > b)
print(f"a est-il supérieur à b ? : {superieur}")
