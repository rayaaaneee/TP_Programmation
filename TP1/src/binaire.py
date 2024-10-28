"""
binaire.py

Objectif :
Convertir et afficher un nombre entier en format binaire

Auteur :
Mohamed AIT EL HADJ

Date :
16/09/2024
"""

num = int(input("Entrez un nombre entier: "))
binaire = []

while num > 0:
    binaire.append(num % 2)
    num //= 2

binaire.reverse()
print("Représentation binaire:", ''.join(map(str, binaire)))
