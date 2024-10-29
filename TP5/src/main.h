#ifndef MAIN_H
#define MAIN_H

#define MAX_VARIABLES 100
#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 100
#define MAX_BUFFER_SIZE 1024

typedef enum { INTEGER, REAL, STRING, UNKNOWN } VarType;

// Structure de données pour une variable
typedef struct {
    char name[MAX_NAME_LEN];
    VarType type;
    union {
        int intValue;
        double realValue;
        char stringValue[MAX_VALUE_LEN];
    } value;
} Variable;

// Supprimer les espaces en début et fin de chaîne
void trim(char *str);

// Récupérer le type de la valeur (entier, réel, chaîne de caractères)
VarType get_type(const char *value);


// Définir une variable
void set_variable(const char *name, VarType type, const char *value);

// Récupérer la valeur d'une variable
void get_variable(const char *name);

// Récupérer le résultat d'une expression
int get_result(char *expression);

// Afficher le résultat d'une expression, utilise la 
// fonction get_result pour récupérer le résultat
void print_result(char* expression);

// Convertir une expression infixée en postfixée
char *parse_postfix(char *infix);

// Évaluer une expression postfixée
int evaluer(char *postfix);

// Afficher les règles de l'interpréteur
void print_rules();

#endif // MAIN_H