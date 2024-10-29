#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include"parseur.h"

bool verify_operation(Operation operation) {
    bool result = true;
    // On vérifie les types des tokens de l'opérateur et des opérandes
    if (operation.main_operator.type != TOKEN_OPERATOR && operation.main_operator.type != TOKEN_UNKNOWN) {
        printf("Error in operator type\n");
        result = false;
    } else if (operation.operand1.type != TOKEN_NUMBER || operation.operand2.type != TOKEN_NUMBER) {
        print_token(operation.operand1);
        print_token(operation.operand2);
        printf("Error in operand type\n");
        result = false;
    }
    return result;
}

void print_operation(Operation operation) {
    printf("Operand 1 : %s, Operator : %s, Operand 2 : %s\n", operation.operand1.value, operation.main_operator.value, operation.operand2.value);
}

Operation process_tokens(Token* tokens, int token_count) {
    
    Operation operation = (Operation) {};

    // On vérifie qu'on a bien 3 tokens
    for (int i = 0; i < token_count; i++) {
        switch (i) {
            case 0:
                operation.operand1 = tokens[i];
                break;
            case 1:
                operation.main_operator = tokens[i];
                break;
            case 2:
                operation.operand2 = tokens[i];
                break;
            default:
                printf("Error, too many tokens\n");
                exit(1);
                break;
        }
    }

    // On vérifie que l'opération est valide
    if (!verify_operation(operation)) {
        exit(1);
    }

    return operation;
}