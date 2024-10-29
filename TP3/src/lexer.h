#ifndef LEXER_H
#define LEXER_H

// Définition des types de tokens
typedef enum {
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_UNKNOWN,
    TOKEN_END,
} TokenType;

// Structure de données pour un token
typedef struct {
    TokenType type;
    char value[256];
} Token;

// Afficher un token
void print_token(Token token);

// Afficher les tokens
void print_tokens(Token* tokens, int token_count);

// Obtenir le prochain token
Token get_next_token(const char **input);

#endif // LEXER_H