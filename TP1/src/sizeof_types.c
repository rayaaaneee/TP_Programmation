#include <stdio.h>
#include "sizeof_types.h"

/*
* sizeof_types.c
*
* Objectif :
* Fichier qui affiche la taille en octets de différents types de variables
*
* Auteur :
* Mohamed AIT EL HADJ
*
* Date :
* 16/09/2024
*/

void sizeof_types()
{
    printf("Taille en octets d'un char : %d \n", sizeof(char));
    printf("Taille en octets d'un short : %d \n", sizeof(short));
    printf("Taille en octets d'un int : %d \n", sizeof(int));
    printf("Taille en octets d'un long int : %d \n", sizeof(long int));
    printf("Taille en octets d'un long long int : %d \n", sizeof(long long int));
    printf("Taille en octets d'un float : %d \n", sizeof(float));
    printf("Taille en octets d'un double : %d \n", sizeof(double));
    printf("Taille en octets d'un long double : %d \n", sizeof(long double));
    printf("Taille en octets d'un char signed : %d \n", sizeof(signed char));
    printf("Taille en octets d'un short signed : %d \n", sizeof(signed short));
    printf("Taille en octets d'un int signed : %d \n", sizeof(signed int));
    printf("Taille en octets d'un long int signed : %d \n", sizeof(signed long int));
}