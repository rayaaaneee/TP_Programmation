#ifndef PARSEUR_H
#define PARSEUR_H
#include"lexer.h"
#include<stdbool.h>

// Structure de données pour une opération
typedef struct {
    Token operand1;
    Token main_operator;
    Token operand2;
} Operation;

// Vérifier si l'opération est valide
bool verify_operation(Operation operation);

// Afficher une opération
void print_operation(Operation operation);

// Traiter les tokens pour obtenir une opération
Operation process_tokens(Token* tokens, int token_count);

#endif