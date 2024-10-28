#include"evaluation.h"
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

float get_result(Operation operation) {
    char *endptr;
    char *endptr2;
    float number1 = (float)strtof(operation.operand1.value, &endptr);
    float number2 = (float)strtof(operation.operand2.value, &endptr2);

    if(*endptr != '\0' | *endptr2 != '\0') {
        printf("Conversion stopped before processing number\n");
    }

    if (strcmp(operation.main_operator.value, "*") == 0) {
        return number1 * number2;
    } else if (strcmp(operation.main_operator.value, "/") == 0) {
        return number1 / number2;
    } else if (strcmp(operation.main_operator.value, "+") == 0) {
        return number1 + number2;
    } else if (strcmp(operation.main_operator.value, "-") == 0) {
        return number1 - number2;
    } else {
        printf("An error occured, unrecognized operator \"%s\"", operation.main_operator.value);
        exit(1);
    }
}

float get_operations_result(Operation* operations, int operation_count) {
    float result = 0;

    for (int i = 0; i < operation_count; i++) {
        if (operations[i].priority == 1 && operations[i].result == 0F) {
            if (operations[i + 1])
            operations[i].result = get_result(operations[i]);
        } else if (operations[i].priority == 0) {
            result = get_result(operations[i]);
        }
    }
    return result;
}

void print_result(Operation operation) {
    float result = get_result(operation);
    printf("Result : %s %s %s = %.2f\n", operation.operand1.value, operation.main_operator.value, operation.operand2.value, result);
}

void print_results(const char *input, Operation* operations, int operation_count) {
    float result = get_operations_result(operations, operation_count);
    printf("Result of %s = %.2f\n", input, result);
}

int main() {
    const char *input = "2 * 5 * 3 + 3";
    const char *p = input;
    Token token;
    Token *tokens = malloc(100 * sizeof(Token));
    int token_count = 0;

    do {
        token = get_next_token(&p);
        if (token.type != TOKEN_END) tokens[token_count++] = token;
    } while (token.type != TOKEN_END);
    
    ProcessTokensResult result = process_tokens(tokens, token_count);
    Operation *operations = result.operations;
    int operation_count = result.operation_count;
    print_operations(operations, operation_count);
    print_results(input, operations, operation_count);
    
    return 0;
}