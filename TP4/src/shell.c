#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pile.h"

/*
* shell.c
*
 * Objectif :
* Interpréteur de commandes pour les fonctions parse_postfix et evaluer.
*
 * Auteur :
* Mohamed AIT EL HADJ
 */


// Prototypes des fonctions de parse_postfix et evaluer
char *parse_postfix(char *infix);
int evaluer(char *postfix);

int main() {
    char input[100];

    printf("Entrez une expression arithmétique (ou 'exit' pour quitter) :\n");

    while (1) {
        printf("> ");
        fgets(input, 100, stdin);
        input[strcspn(input, "\n")] = 0;  // Retirer le caractère de nouvelle ligne

        if (strcmp(input, "exit") == 0) {
            printf("Fermeture de l'interpréteur.\n");
            break;
        }

        // Convertir l'expression infixée en postfixée
        char *postfix = parse_postfix(input);
        if (postfix == NULL) {
            printf("Erreur dans la conversion de l'expression.\n");
            continue;
        }

        // Évaluer l'expression postfixée
        int resultat = evaluer(postfix);
        printf("Résultat : %d\n", resultat);

        free(postfix);  // Libérer la mémoire allouée pour l'expression postfixée
    }

    return 0;
}
