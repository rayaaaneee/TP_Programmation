"""
cercles.py

Objectif :
Calcule l'aire et le périmètre d'un cercle de rayon donné par l'utilisateur

Auteur :
Mohamed AIT EL HADJ

Date :
16/09/2024
"""

pi = 3.14159
print("Saisir la rayon du cercle : ")
rayon = int(input())
aire = pi * rayon * rayon
perimetre = 2 * pi * rayon

print("L'aire de ce cercle est " + str(aire) + " et le perimetre de ce cerle est " + str(perimetre))