#include <stdio.h>
#include "operateur.h"

/*
* opérateurs.c
*
* Objectif :
* Fichier qui permet de tester différentes opérations
*
* Auteur :
* Mohamed AIT EL HADJ
*
* Date :
* 16/09/2024
*/

void operateur() {
    int a = 16;
    int b = 3;

    int addition = a + b;
    printf("Addition : %d + %d = %d\n", a, b, addition);

    int soustraction = a - b;
    printf("Soustraction : %d - %d = %d\n", a, b, soustraction);

    int multiplication = a * b;
    printf("Multiplication : %d * %d = %d\n", a, b, multiplication);

    float division = (float)a / (float)b;
    printf("Division : %d / %d = %.2f\n", a, b, division);

    int modulo = a % b;
    printf("Modulo : %d %% %d = %d\n", a, b, modulo);

    int egal = (a == b);
    printf("a est-il egal a b ? : %d\n", egal);

    int superieur = (a > b);
    printf("a est-il superieur a b ? : %d\n", superieur);
}
