#ifndef STACK_H
#define STACK_H

typedef struct {
    double* data;
    int top;
    int capacity;
}Stack;

Stack* createStack(int capacity);
void push(Stack* stack, double value);
double pop(Stack* stack);
double peek(Stack* stack);
int isEmpty(Stack* stack);
void freeStack(Stack* stack);

#endif