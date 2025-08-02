#include <stdio.h>
#include <stdlib.h>
#include "evaluator.h"
#include "stack.h"

double evaluatePostfix(TokenArray* postfix) {
    Stack* evalStack = createStack(postfix->size);

    for (int i = 0; i < postfix->size; i++) {
        Token token = postfix->tokens[i];
        if (token.type == TOKEN_NUMBER) {
            push(evalStack, token.value);
        }
        else {
            if (evalStack->top < 1) {
                fprintf(stderr, "Invalid expression: Insufficient Operands\n");
                exit(EXIT_FAILURE);
            }

            double right = pop(evalStack);
            double left = pop(evalStack);
            double result = 0.0;

            switch (token.type) {
            case TOKEN_PLUS:
                result = left + right;
                break;

            case TOKEN_MINUS:
                result = left - right;
                break;

            case TOKEN_MULTIPLY:
                result = left * right;
                break;

            case TOKEN_DIVIDE:
                if (right == 0.0) {
                    fprintf(stderr, "Cannot divide by zero\n");
                    exit(EXIT_FAILURE);
                }
                result = left / right;
                break;

            default:
                fprintf(stderr, "Unexpected operator in postfix: %d\n", token.type);
                exit(EXIT_FAILURE);
            }

            push(evalStack, result);
        }
    }

    if (evalStack->top != 0) {
        fprintf(stderr, "Invalid expression: too many operands\n");
        exit(EXIT_FAILURE);
    }

    double finalResult = pop(evalStack);
    freeStack(evalStack);
    return finalResult;
}