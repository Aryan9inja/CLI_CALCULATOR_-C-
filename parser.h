#ifndef PARSER_H
#define PARSER_H

#include "tokenizer.h"

typedef struct {
    Token* tokens;
    int size;
    int capacity;
}TokenArray;

TokenArray* infixToPostfix(const char* expression);
void freeTokenArray(TokenArray* arr);

#endif