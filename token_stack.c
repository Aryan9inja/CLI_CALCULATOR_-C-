#include <stdio.h>
#include <stdlib.h>
#include "token_stack.h"

TokenStack* createTokenStack(int capacity) {
    TokenStack* stack = (TokenStack*)malloc(sizeof(TokenStack));
    if (!stack) {
        perror("Failed to allocate token stack");
        exit(EXIT_FAILURE);
    }

    stack->data = (Token*)malloc(capacity * sizeof(Token));
    if (!stack->data) {
        perror("Failed to allocate token stack data");
        exit(EXIT_FAILURE);
    }

    stack->top = -1;
    stack->capacity = capacity;

    return stack;
}

void pushToken(TokenStack* stack, Token token) {
    if (stack->top >= stack->capacity - 1) {
        fprintf(stderr, "Token stack overflow!\n");
        exit(EXIT_FAILURE);
    }
    stack->data[++stack->top] = token;
}

Token popToken(TokenStack* stack) {
    if (stack->top < 0) {
        fprintf(stderr, "Token stack underflow!\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

Token peekToken(TokenStack* stack) {
    if (stack->top < 0) {
        fprintf(stderr, "Token stack is empty!\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top];
}

int isTokenStackEmpty(TokenStack* stack) {
    return stack->top == -1;
}

void freeTokenStack(TokenStack* stack) {
    if (stack) {
        free(stack->data);
        free(stack);
    }
}