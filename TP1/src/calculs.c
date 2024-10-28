#include <stdio.h>
#include "calculs.h"

/*
* calculs.c
*
* Objectif :
* Ce fichier effectue différentes opérations en fonction d'un opérateur saisi par l'utilisateur
*
* Auteur :
* Mohamed AIT EL HADJ
*
* Date :
* 16/09/2024
*/

void calculs() {
    int num1, num2;
    char op;

    printf("Entrez deux nombres entiers: ");
    scanf("%d %d", &num1, &num2);
    printf("Entrez un operateur (+, -, *, /, %%, &, |, ~): ");
    scanf(" %c", &op);

    switch (op) {
    case '+':
        printf("Resultat: %d\n", num1 + num2);
        break;
    case '-':
        printf("Resultat: %d\n", num1 - num2);
        break;
    case '*':
        printf("Resultat: %d\n", num1 * num2);
        break;
    case '/':
        if (num2 != 0)
            printf("Resultat: %d\n", num1 / num2);
        else
            printf("Erreur: Division par zero\n");
        break;
    case '%':
        if (num2 != 0)
            printf("Resultat: %d\n", num1 % num2);
        else
            printf("Erreur: Division par zero\n");
        break;
    case '&':
        printf("Resultat: %d\n", num1 & num2);
        break;
    case '|':
        printf("Resultat: %d\n", num1 | num2);
        break;
    case '~':
        printf("Resultat: ~%d = %d, ~%d = %d\n", num1, ~num1, num2, ~num2);
        break;
    default:
        printf("Operateur non valide\n");
        break;
    }
}
