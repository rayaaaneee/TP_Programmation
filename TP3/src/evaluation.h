#ifndef EVALUATION_H
#define EVALUATION_H

#include"parseur.h"
#include"lexer.h"
#include<stdbool.h>

float get_operation_result(Operation operation);

float get_operations_result(Operation* operations, int operation_count);

void print_result(Operation operation);

void print_results(const char* input, Operation* operations, int operation_count);

#endif // EVALUATION_H