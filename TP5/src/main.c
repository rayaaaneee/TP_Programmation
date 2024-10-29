#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include"main.h"

Variable symbolTable[MAX_VARIABLES];
int variableCount = 0;

VarType getType(const char *value) {
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

char* getStringType(VarType type) {
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

void setVariable(const char* name, VarType type, const char* value) {
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

void getVariable(const char *name) {
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

int main() {
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
            setVariable(name, getType(value), value);
        } else if (strstr(input, "lambda") != NULL) {
            char expr[100];
            char called_var[MAX_NAME_LEN];
            
            if (sscanf(input, "(lambda x.%[^)]) %s", expr, called_var) == 2) {
                printf("Expression : %s\n", expr);
                printf("Variable appelée : %s\n", called_var);
            } else {
                printf("Erreur : expression lambda mal formatée.\n");
            }
            
        } else {
            char name[MAX_NAME_LEN];
            sscanf(input, "%s", name);
            getVariable(name);
        }
    } while (1);


    return 0;
}