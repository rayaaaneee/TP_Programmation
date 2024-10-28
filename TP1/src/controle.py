"""
controle.py

Objectif :
Fichier qui permet d'afficher les nombres de 1 à 1000 qui sont divisibles par 4 mais pas par 6, les nombres de 1 à 1000
qui sont pairs et divisibles par 8 et les nombres de 1 à 1000 qui sont divisibles par 5 ou 7, mais ne sont pas divisibles par 10.

Auteur :
Mohamed AIT EL HADJ

Date :
16/09/2024
"""

print("Divisibles par 4 mais pas par 6:")
for i in range(1, 1001):
    if i % 4 == 0 and i % 6 != 0:
        print(i, end=" ")
print()

print("Pairs et divisibles par 8:")
for i in range(1, 1001):
    if i % 2 == 0 and i % 8 == 0:
        print(i, end=" ")
print()

print("Divisibles par 5 ou 7 mais pas par 10:")
for i in range(1, 1001):
    if (i % 5 == 0 or i % 7 == 0) and i % 10 != 0:
        print(i, end=" ")
print()
