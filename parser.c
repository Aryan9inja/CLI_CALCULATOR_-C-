#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "token_stack.h"

static int precedence(TokenType type) {
    switch (type) {
    case TOKEN_PLUS:
    case TOKEN_MINUS:
        return 1;
        break;

    case TOKEN_MULTIPLY:
    case TOKEN_DIVIDE:
        return 2;
        break;

    default:
        return 0;
        break;
    }
}

static void addToken(TokenArray* arr, Token token) {
    if (arr->size >= arr->capacity) {
        arr->capacity *= 2;
        arr->tokens = realloc(arr->tokens, arr->capacity * sizeof(Token));
        if (!arr->tokens) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
    }
    arr->tokens[arr->size++] = token;
}

TokenArray* infixToPostfix(const char* expression) {
    TokenArray* output = malloc(sizeof(TokenArray));
    output->size = 0;
    output->capacity = 16;
    output->tokens = malloc(output->capacity * sizeof(Token));

    TokenStack* operatorStack = createTokenStack(64);

    int index = 0;
    Token token = getNextToken(expression, &index);

    while (token.type != TOKEN_END && token.type != TOKEN_INVALID) {
        if (token.type == TOKEN_NUMBER) {
            addToken(output, token);
        }
        else if (token.type == TOKEN_LPAREN) {
            pushToken(operatorStack, token);
        }
        else if (token.type == TOKEN_RPAREN) {
            while (!isTokenStackEmpty(operatorStack) && peekToken(operatorStack).type != TOKEN_LPAREN) {
                addToken(output, popToken(operatorStack));
            }
            if (!isTokenStackEmpty(operatorStack) && peekToken(operatorStack).type == TOKEN_LPAREN) {
                popToken(operatorStack);
            }
            else {
                fprintf(stderr, "Mismatched paranthesis in expression\n");
                exit(EXIT_FAILURE);
            }
        }
        else {
            while (!isTokenStackEmpty(operatorStack) && precedence(peekToken(operatorStack).type) >= precedence(token.type)) {
                addToken(output, popToken(operatorStack));
            }
            pushToken(operatorStack, token);
        }

        token = getNextToken(expression, &index);
    }

    while (!isTokenStackEmpty(operatorStack)) {
        if (peekToken(operatorStack).type == TOKEN_LPAREN || peekToken(operatorStack).type == TOKEN_RPAREN) {
            fprintf(stderr, "Mismatched paranthesis in expression\n");
        }

        addToken(output, popToken(operatorStack));
    }

    freeTokenStack(operatorStack);
    return output;
}

void freeTokenArray(TokenArray* arr){
    if(arr){
        free(arr->tokens);
        free(arr);
    }
}