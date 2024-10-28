#include <stdio.h>
#include "variables.h"

/*
* variables.c
*
* Objectif :
* Fichier qui permet de tester l'affichage des différents types de variables
*
* Auteur :
* Mohamed AIT EL HADJ
*
* Date :
* 16/09/2024
*/

void variables() {
    char c = 'A';
    signed char sc = -120;
    unsigned char uc = 250;
    short s = -32000;
    unsigned short us = 65000;
    int i = -2147483647;
    unsigned int ui = 4294967295U;
    long int li = -9223372036854775807L;
    unsigned long int uli = 18446744073709551615UL;
    long long int lli = -9223372036854775807LL;
    float f = 3.14f;
    double d = 3.141592653589793;
    long double ld = 3.14159265358979323846264338327950288L;

    printf("char: %c\n", c);
    printf("signed char: %d\n", sc);
    printf("unsigned char: %u\n", uc);
    printf("short: %d\n", s);
    printf("unsigned short: %u\n", us);
    printf("int: %d\n", i);
    printf("unsigned int: %u\n", ui);
    printf("long int: %ld\n", li);
    printf("unsigned long int: %lu\n", uli);
    printf("long long int: %lld\n", lli);
    printf("float: %f\n", f);
    printf("double: %lf\n", d);
    printf("long double: %Lf\n", ld);
}
