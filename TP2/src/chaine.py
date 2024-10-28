def lenChaine(chaine):
    longueur = 0
    for char in chaine:
        longueur += 1
    return longueur

def copie(chaine1):
    chaine2 = ''
    for char in chaine1:
        chaine2 += char
    return chaine2

def concat(chaine1, chaine2):
    resultat = chaine1  # Initialiser avec chaine1
    for char in chaine2:
        resultat += char
    return resultat

def main():
    # Saisir les chaînes
    chaine1 = input("Saisir la première chaîne : ")
    chaine2 = input("Saisir la deuxième chaîne : ")

    # Longueur de la première chaîne
    print(f"Longueur de la première chaîne : {lenChaine(chaine1)}")
    print("#################")

    # Copier chaine1
    copier = copie(chaine1)
    print(f"Chaîne copiée : {copier}")
    print("#################")

    # Concaténer les deux chaînes
    resultat = concat(chaine1, chaine2)
    print(f"Concaténation des deux chaînes : {resultat}")

if __name__ == "__main__":
    main()
