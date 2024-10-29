#ifndef MAIN_H
#define MAIN_H

#define MAX_VARIABLES 100
#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 100
#define MAX_BUFFER_SIZE 1024

typedef enum { INTEGER, REAL, STRING, UNKNOWN } VarType;

typedef struct {
    char name[MAX_NAME_LEN];
    VarType type;
    union {
        int intValue;
        double realValue;
        char stringValue[MAX_VALUE_LEN];
    } value;
} Variable;

void trim(char *str);

VarType get_type(const char *value);

void set_variable(const char *name, VarType type, const char *value);

void get_variable(const char *name);

int get_result(char *expression);

void print_result(char* expression);

char *parse_postfix(char *infix);

int evaluer(char *postfix);

void print_rules();

#endif // MAIN_H