#ifndef PARSEUR_H
#define PARSEUR_H
#include"lexer.h"
#include<stdbool.h>

typedef struct {
    Token operand1;
    Token main_operator;
    Token operand2;
    int priority;
    float result;
} Operation;

typedef struct {
    Operation* operations;
    int operation_count;
} ProcessTokensResult;

bool verify_operation(Operation operation);

void print_operation(Operation operation);

void print_operations(Operation* operations, int operation_count);

ProcessTokensResult process_tokens(Token* tokens, int token_count);

#endif