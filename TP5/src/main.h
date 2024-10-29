#ifndef MAIN_H
#define MAIN_H

#define MAX_VARIABLES 100
#define MAX_NAME_LEN 100
#define MAX_VALUE_LEN 100

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

VarType getType(const char *value);

void setVariable(const char *name, VarType type, const char *value);

void getVariable(const char *name);

#endif // MAIN_H