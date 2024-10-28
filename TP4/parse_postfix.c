#include <stdio.h>
#include <stdlib.h>
#include "pile.h"

/*
* parse_postfix.c
*
 * Objectif :
* Fonction qui prend en entrée une chaîne de caractères représentant une expression arithmétique en notation infixée
* et retourne une chaîne de caractères représentant la même expression en notation postfixée.
*
 * Auteur :
* Mohamed AIT EL HADJ
 */

int priority(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

char *parse_postfix(char *infix) {
    Pile operateurs;
    initPile(&operateurs);
    int i = 0, j = 0;
    char *result = (char *)malloc(sizeof(char) * 100);

    while (infix[i] != '\0') {
        if (infix[i] >= '0' && infix[i] <= '9') {
            result[j] = infix[i];
            j++;
            i++;
        } else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
            while (!estVide(&operateurs) && priority(sommet(&operateurs)) >= priority(infix[i])) {
                result[j] = depiler(&operateurs);
                j++;
            }
            empiler(&operateurs, infix[i]);
            i++;
        } else if (infix[i] == '(') {
            empiler(&operateurs, infix[i]);
            i++;
        } else if (infix[i] == ')') {
            while (!estVide(&operateurs) && sommet(&operateurs) != '(') {
                result[j] = depiler(&operateurs);
                j++;
            }
            if (!estVide(&operateurs) && sommet(&operateurs) == '(') {
                depiler(&operateurs);
            }
            i++;
        } else {
            printf("Caractère non reconnu.\n");
            i++;
        }
    }

    while (!estVide(&operateurs)) {
        result[j] = depiler(&operateurs);
        j++;
    }
    result[j] = '\0';

    return result;
}
/*
int main() {
    char infix[100];
    printf("Entrez une expression arithmétique en notation infixée: ");
    scanf("%s", infix);
    char *postfix = parse_postfix(infix);
    printf("Infix: %s\n", infix);
    printf("Postfix: %s\n", postfix);
    free(postfix);
    return 0;
}
*/
