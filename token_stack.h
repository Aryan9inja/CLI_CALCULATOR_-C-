#ifndef TOKEN_STACK_H
#define TOKEN_STACK_H

#include "tokenizer.h"

typedef struct {
    Token* data;
    int top;
    int capacity;
} TokenStack;

TokenStack* createTokenStack(int capacity);
void pushToken(TokenStack* stack, Token token);
Token popToken(TokenStack* stack);
Token peekToken(TokenStack* stack);
int isTokenStackEmpty(TokenStack* stack);
void freeTokenStack(TokenStack* stack);

#endif
