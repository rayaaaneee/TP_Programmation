#ifndef LEXER_H
#define LEXER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_UNKNOWN,
    TOKEN_END,
} TokenType;

typedef struct {
    TokenType type;
    char value[256];
} Token;

void print_token(Token token);

void print_tokens(Token* tokens, int token_count);

Token get_next_token(const char **input);

#endif // LEXER_H