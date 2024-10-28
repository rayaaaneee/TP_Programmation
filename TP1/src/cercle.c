#include <stdio.h>
#include "cercle.h"

/*
* cercle.c
*
* Objectif :
* Calcule l'aire et le périmètre d'un cercle de rayon donné par l'utilisateur
*
* Auteur :
* Mohamed AIT EL HADJ
*
* Date :
* 16/09/2024
*/

void cercle(void)
{
    float pi = 3.14159;
    int rayon;
    printf("Saisir la valeur du rayon du cercle\n");
    scanf("%d",&rayon);
    float aire = pi * rayon * rayon;
    float perimetre = 2 * pi * rayon;

    printf("L'aire de ce cercle est : %f et le perimetre de ce cercle est %f", aire,perimetre);
}
