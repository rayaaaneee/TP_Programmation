#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include"parseur.h"

bool verify_operation(Operation operation) {
    bool result = true;
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

void print_operations(Operation* operations, int operation_count) {
    for (int i = 0; i < operation_count; i++) {
        print_operation(operations[i]);
    }
}

ProcessTokensResult process_tokens(Token* tokens, int token_count) {
    
    Operation* operations = malloc(100 * sizeof(Operation));

    int index_operation = 0;

    int index_token = 0;

    while (index_token < token_count) {
        if (tokens[index_token].type == TOKEN_END) {
            break;
        }
        switch ((index_token + index_operation) % 3)
        {
            case 0:
                operations[index_operation].operand1 = tokens[index_token];
                index_token++;
                break;
            case 1:
                operations[index_operation].main_operator = tokens[index_token];
                if (operations[index_operation].main_operator.value == "*" || operations[index_operation].main_operator.value == "/") {
                    operations[index_operation].priority = 1;
                } else {
                    operations[index_operation].priority = 0;
                }
                index_token++;
                break;
            case 2:
                operations[index_operation].operand2 = tokens[index_token];
                if (!verify_operation(operations[index_operation])) {
                    printf("An error occured in this operation : \n");
                    print_operation(operations[index_operation]);
                    exit(1);
                } else {
                    index_operation++;
                }
                break;
        }
    }

    free(tokens);

    Operation* temp = realloc(operations, index_operation * sizeof(Operation));

    if (temp == NULL) {
        perror("Failed to reallocate memory");
        free(operations);
        exit(1);
    }
    operations = temp;

    return (ProcessTokensResult) { operations, index_operation };
}