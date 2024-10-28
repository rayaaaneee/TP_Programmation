"""
boucles.py

Objectif :
Dessine un triangle en alternant (* et #) pour le remplissage avec une taille saisi par l'utilisateur

Auteur :
Mohamed AIT EL HADJ

Date :
16/09/2024
"""

def for_triangle() :
    compteur = int(input("Entrez la taille du triangle : "))

    for i in range(1, compteur + 1):
        for j in range(1, i + 1):
            if i == 1 or i == compteur or j == 1 or j == i:
                print("*", end=" ")
            else:
                print("#", end=" ")
        print()

def while_triangle() :
    compteur = int(input("Entrez la taille du triangle : "))
    i = 1

    while i <= compteur:
        j = 1
        while j <= i:
            if i == 1 or i == compteur or j == 1 or j == i:
                print("*", end=" ")
            else:
                print("#", end=" ")
            j += 1
        print()
        i += 1

while_triangle()