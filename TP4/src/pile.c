#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

/*
* pile.c
*
 * Objectif :
* Implémentation d'une pile
*
 * Auteur :
* Mohamed AIT EL HADJ
 */

// Fonction pour initialiser la pile
void initPile(Pile *p) {
    p->sommet = NULL;
}

// Fonction pour vérifier si la pile est vide
int estVide(Pile *p) {
    return p->sommet == NULL;
}

// Fonction pour empiler un élément
void empiler(Pile *p, char valeur) {
    Element *nouveau = (Element *)malloc(sizeof(Element));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire.\n");
        exit(EXIT_FAILURE);
    }

    nouveau->valeur = valeur;
    nouveau->precedent = NULL;
    nouveau->suivant = p->sommet;


    if (p->sommet != NULL) {
        p->sommet->precedent = nouveau;
    }

    p->sommet = nouveau;
}

// Fonction pour dépiler un élément
char depiler(Pile *p) {
    if (estVide(p)) {
        printf("Pile vide. Impossible de dépiler.\n");
        return -1;
    }

    Element *aSupprimer = p->sommet;
    char valeur = aSupprimer->valeur;

    p->sommet = p->sommet->suivant;

    if (p->sommet != NULL) {
        p->sommet->precedent = NULL;
    }

    free(aSupprimer);
    return valeur;
}

// Fonction pour obtenir la valeur au sommet sans dépiler
char sommet(Pile *p) {
    if (estVide(p)) {
        printf("Pile vide.\n");
        return -1;
    }
    return p->sommet->valeur;
}

// Fonction pour afficher les éléments de la pile
void afficherPile(Pile *p) {
    if (estVide(p)) {
        printf("Pile vide.\n");
        return;
    }

    Element *courant = p->sommet;
    printf("Contenu de la pile : ");
    while (courant != NULL) {
        printf("%c ", courant->valeur);
        courant = courant->suivant;
    }
    printf("\n");
}

