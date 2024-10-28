#ifndef PILE_H
#define PILE_H

/*
* pile.h
*
 * Objectif :
* Implémentation d'une pile
*
 * Auteur :
* Mohamed AIT EL HADJ
 */

// Structure représentant un élément de la pile
typedef struct Element {
    char valeur;
    struct Element *precedent;
    struct Element *suivant;
} Element;

// Structure représentant la pile
typedef struct {
    Element *sommet;
} Pile;

// Fonction pour initialiser la pile
void initPile(Pile *p);

// Fonction pour vérifier si la pile est vide
int estVide(Pile *p);

// Fonction pour empiler un élément
void empiler(Pile *p, char valeur);

// Fonction pour dépiler un élément
char depiler(Pile *p);

// Fonction pour afficher la pile
void afficherPile(Pile *p);

// Fonction pour retourner la valeur du sommet de la pile
char sommet(Pile *p);

#endif // PILE_H