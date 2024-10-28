#include <stdio.h>
#include "binaire.h"

/*
* binaire.c
*
* Objectif :
* Convertir et afficher un nombre entier en format binaire
*
* Auteur :
* Mohamed AIT EL HADJ
*
* Date :
* 16/09/2024
*/

void binaire() {
    int num, i;
    int binaire[32];

    printf("Entrez un nombre entier: ");
    scanf("%d", &num);

    for (i = 31; i >= 0; i--) {
        binaire[i] = num % 2;
        num /= 2;
    }

    printf("Representation binaire: ");
    for (i = 0; i < 32; i++) {
        printf("%d", binaire[i]);
    }
    printf("\n");
}
