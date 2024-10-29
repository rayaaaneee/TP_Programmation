#ifndef EVALUATION_H
#define EVALUATION_H

#include"parseur.h"
#include"lexer.h"
#include<stdbool.h>

// Calculer le résultat d'une opération
float get_result(Operation operation);

// Afficher le résultat d'une opération, utilise la fonction get_result pour récupérer le résultat
void print_result(Operation operation);

#endif // EVALUATION_H