#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

/*
* evaluer.c
*
 * Objectif :
* Fonction qui prend en entrée une chaîne de caractères représentant une expression arithmétique en notation postfixée
* et retourne le résultat de l'évaluation de cette expression.
*
 * Auteur :
* Mohamed AIT EL HADJ
 */

int evaluer(char *postfix) {
    Pile operandes;
    initPile(&operandes);
    int i = 0;

    while (postfix[i] != '\0') {
        if (postfix[i] >= '0' && postfix[i] <= '9') {
            empiler(&operandes, postfix[i] - '0');
        } else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/') {
            int op2 = depiler(&operandes);
            int op1 = depiler(&operandes);
            int resultat;

            switch (postfix[i]) {
                case '+':
                    resultat = op1 + op2;
                    break;
                case '-':
                    resultat = op1 - op2;
                    break;
                case '*':
                    resultat = op1 * op2;
                    break;
                case '/':
                    resultat = op1 / op2;
                    break;
            }

            empiler(&operandes, resultat);
        }

        i++;
    }

    return depiler(&operandes);
}
/*
int main() {
    char postfix[100];
    printf("Entrez une expression arithmetique en notation postfixee : ");
    scanf("%s", postfix);
    printf("Resultat : %d\n", evaluer(postfix));

    return 0;
}
*/
