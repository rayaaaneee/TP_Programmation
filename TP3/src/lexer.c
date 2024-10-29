#include"lexer.h"
#include"stdio.h"
#include"ctype.h"
#include"string.h"

void print_tokens(Token* tokens, int token_count) {
    for (int i = 0; i < token_count; i++) {
        print_token(tokens[i]);
    }
}

void print_token(Token token) {
    switch (token.type) {
        case TOKEN_NUMBER:
            printf("Number: %s\n", token.value);
            break;
        case TOKEN_OPERATOR:
            printf("Operator: %s\n", token.value);
            break;
        case TOKEN_UNKNOWN:
            printf("Unknown: %s\n", token.value);
            break;
        case TOKEN_END:
            printf("End of input\n");
            break;
    }
}

Token get_next_token(const char **input) {
    while (isspace(**input)) (*input)++;

    if (**input == '\0') {
        return (Token){TOKEN_END, ""};
    }

    if (isdigit(**input) || **input == '.') {
        Token token = {TOKEN_NUMBER, ""};
        int i = 0;
        while (isdigit(**input) || **input == '.') {
            token.value[i++] = *(*input)++;
        }
        token.value[i] = '\0';
        return token;
    }

    if (strchr("+-*/", **input)) {
        Token token = {TOKEN_OPERATOR, ""};
        token.value[0] = *(*input)++;
        token.value[1] = '\0';
        return token;
    }

    Token token = {TOKEN_UNKNOWN, ""};
    token.value[0] = *(*input)++;
    token.value[1] = '\0';
    return token;
}