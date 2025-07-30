#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        perror("Failed to allocate stack");
        exit(EXIT_FAILURE);
    }

    stack->data = (double*)malloc(capacity * sizeof(double));
    if (!stack->data) {
        perror("Failed to allocate stack data");
        exit(EXIT_FAILURE);
    }

    stack->top = -1;
    stack->capacity = capacity;

    return stack;
}

void push(Stack* stack, double value) {
    if (stack->top >= stack->capacity - 1) {
        fprintf(stderr, "Stack Overflow!\n");
        exit(EXIT_FAILURE);
    }

    stack->data[++stack->top] = value;
}

double pop(Stack* stack) {
    if (stack->top < 0) {
        fprintf(stderr, "Stack Underflow!\n");
        exit(EXIT_FAILURE);
    }

    return stack->data[stack->top--];
}

double peek(Stack* stack) {
    if (stack->top < 0) {
        fprintf(stderr, "Stack is empty!\n");
        exit(EXIT_FAILURE);
    }

    return stack->data[stack->top];
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void freeStack(Stack* stack) {
    if (stack) {
        free(stack->data);
        free(stack);
    }
}