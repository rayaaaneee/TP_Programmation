#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"main.h"
#include"interpreteur/pile.h"

Variable symbolTable[MAX_VARIABLES];
int variableCount = 0;

VarType get_type(const char *value) {
    if (isdigit(value[0])) {
        if (strchr(value, '.') != NULL) {
            return REAL;
        }
        return INTEGER;
    } else if (value[0] == '"' && value[strlen(value) - 1] == '"') {
        return STRING;
    } else {
        return UNKNOWN;
    }
}

char* get_string_type(VarType type) {
    switch (type) {
        case INTEGER:
            return "entier";
        case REAL:
            return "nombre réel";
        case STRING:
            return "chaîne de caractères";
        case UNKNOWN:
        default:
            return "inconnu";
    }
}

void set_variable(const char* name, VarType type, const char* value) {
    if (variableCount == MAX_VARIABLES) {
        printf("Erreur : nombre maximal de variables atteint\n");
        return;
    }
    if (type == UNKNOWN) {
        printf("Erreur : type non reconnu\n");
        return;
    }
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            if (symbolTable[i].type != type) {
                printf("Erreur : changement de type non autorisé pour la variable %s\n", name);
                return;
            }
            switch (type) {
                case INTEGER:
                    symbolTable[i].value.intValue = atoi(value);
                    break;
                case REAL:
                    symbolTable[i].value.realValue = strtod(value, NULL);
                    break;
                case STRING:
                    strcpy(symbolTable[i].value.stringValue, (char *)value);
                    break;
            }
            printf("Variable %s mise à jour avec la valeur ", name);
            switch (type) {
                case INTEGER:
                    printf("%d (integer)\n", symbolTable[i].value.intValue);
                    break;
                case REAL:
                    printf("%f (real)\n", symbolTable[i].value.realValue);
                    break;
                case STRING:
                    printf("%s (string)\n", symbolTable[i].value.stringValue);
                    break;
            }
            return;
        }
    }
    strcpy(symbolTable[variableCount].name, name);
    symbolTable[variableCount].type = type;
    switch (type) {
        case INTEGER:
            symbolTable[variableCount].value.intValue = atoi(value);
            break;
        case REAL:
            symbolTable[variableCount].value.realValue = strtod(value, NULL);
            break;
        case STRING:
            strcpy(symbolTable[variableCount].value.stringValue, (char *)value);
            break;
    }
    printf("Variable %s définie avec la valeur ", name);
    switch (type) {
        case INTEGER:
            printf("%d (integer)\n", symbolTable[variableCount].value.intValue);
            break;
        case REAL:
            printf("%f (real)\n", symbolTable[variableCount].value.realValue);
            break;
        case STRING:
            printf("%s (string)\n", symbolTable[variableCount].value.stringValue);
            break;
    }
    variableCount++;
}

void get_variable(const char *name) {
    for (int i = 0; i < variableCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            printf("Variable %s a la valeur ", name);
            switch (symbolTable[i].type) {
                case INTEGER:
                    printf("%d (integer)\n", symbolTable[i].value.intValue);
                    break;
                case REAL:
                    printf("%f (real)\n", symbolTable[i].value.realValue);
                    break;
                case STRING:
                    printf("\"%s\" (string)\n", symbolTable[i].value.stringValue);
                    break;
            }
            return;
        }
    }
    printf("Erreur : la variable %s n'est pas définie\n", name);
}

int get_result(char *expression) {

    // Convertir l'expression infixée en postfixée
    char *postfix = parse_postfix(expression);
    if (postfix == NULL) {
        printf("Erreur dans la conversion de l'expression.\n");
        exit(1);
    }

    // Évaluer l'expression postfixée
    int resultat = evaluer(postfix);

    free(postfix);
    
    return resultat;
}

void print_result(char* expression) {
    int result = get_result(expression);
    printf("Résultat : %s = %d\n", expression, result);
}

void print_rules() {
    printf("Bienvenue dans l'interpréteur de commandes.\n");
    printf("- Tapez 'exit' pour quitter.\n");
    printf("- Tapez une expression de la forme 'nom_variable' ou 'nom_variable = valeur' pour définir ou obtenir la valeur d'une variable.\n");
    printf("- Tapez une expression de la forme '(lambda x.expression) valeur' pour évaluer une expression lambda.\n");
    printf("La valeur de x sera remplacée par la valeur de la variable appelée, une valeur dure peut être mise aussi.\n");
    printf("Exemple : (lambda x.x+1) 2\n");
    printf("Exemple : (lambda x.(x+1)*2) y\n");
    printf("Veuillez ne pas mettre d'espace dans l'expression lambda.\n");
    printf("\n-----------------------------------------------\n\n");
}

int main() {

    print_rules();

    char input[100];
    do {
        printf("> ");
        fgets(input, 100, stdin);
        input[strlen(input) - 1] = '\0';
        if (strcmp(input, "exit") == 0) {
            break;
        }
        if (strstr(input, "=") != NULL) {
            char name[MAX_NAME_LEN];
            char value[MAX_VALUE_LEN];
            char type[10];
            sscanf(input, "%s = %s", name, value);
            set_variable(name, get_type(value), value);
        } else if (strstr(input, "lambda") != NULL) {
            char expr[100];
            char called_var[MAX_NAME_LEN];
            
            if (sscanf(input, "(lambda x.%[^)]) %s", expr, called_var) == 2) {
                if (!isdigit(called_var[0])) {
                    // remplacer x par la valeur de la variable appelée
                    char expr_with_replaced_var[100];
                    strcpy(expr_with_replaced_var, expr);
                    for (int i = 0; i < variableCount; i++) {
                        if (strcmp(symbolTable[i].name, called_var) == 0) {
                            switch (symbolTable[i].type) {
                                case INTEGER:
                                case REAL:
                                    char value[100];
                                    if (symbolTable[i].type == INTEGER) {
                                        sprintf(value, "%d", symbolTable[i].value.intValue);
                                    } else {
                                        sprintf(value, "%f", symbolTable[i].value.realValue);
                                    }
                                    char *pos = strstr(expr_with_replaced_var, called_var);
                                    while (pos != NULL) {
                                        int len = strlen(called_var);
                                        memmove(pos + strlen(value), pos + len, strlen(pos) - len + 1);
                                        memcpy(pos, value, strlen(value));
                                        pos = strstr(pos + strlen(value), called_var);
                                    }
                                    break;
                                case STRING:
                                    printf("Error : cannot replace variable with string value.\n");
                                    break;
                            }
                        }
                    }
                    strcpy(expr, expr_with_replaced_var);
                }
                print_result(expr);
            } else {
                printf("Erreur : expression lambda mal formatée.\n");
            }
            
        } else {
            char name[MAX_NAME_LEN];
            sscanf(input, "%s", name);
            get_variable(name);
        }
    } while (1);


    return 0;
}