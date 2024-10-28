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

void print_result(Operation operation) {
    float result = get_result(operation);
    printf("Result : %s %s %s = %.2f\n", operation.operand1.value, operation.main_operator.value, operation.operand2.value, result);
}

int main() {
    const char *input = "2.3 + 5.5";
    const char *p = input;
    Token token;
    Token *tokens = malloc(100 * sizeof(Token));
    int token_count = 0;

    do {
        token = get_next_token(&p);
        if (token.type != TOKEN_END) tokens[token_count++] = token;
    } while (token.type != TOKEN_END);
    
    Operation operation = process_tokens(tokens, token_count);

    print_result(operation);
    
    return 0;
}