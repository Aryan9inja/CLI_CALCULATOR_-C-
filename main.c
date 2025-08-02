#include <stdio.h>
#include <string.h>

#include "parser.h"
#include "evaluator.h"

#define MAX_INPUT_SIZE 256

int main() {
    char input[MAX_INPUT_SIZE];

    printf("Welcome to CLI Calculator\n");
    printf("Enter 'exit' to quit\n");

    while (1) {
        printf("Enter an expression: ");
        if (!fgets(input, sizeof(input), stdin)) {
            printf("Input error, exiting...\n");
            break;
        }

        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') input[len - 1] = '\0';

        if (strcmp(input, "exit") == 0) break;

        TokenArray* postfix = infixToPostfix(input);
        if (!postfix || postfix->size == 0) {
            fprintf(stderr, "Failed to parse expression.\n");
            continue;
        }
        double result=evaluatePostfix(postfix);
        printf("Result: %.2lf\n",result);

        freeTokenArray(postfix);
    }

    printf("Goodbye :)\n");
    return 0;
}