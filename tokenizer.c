#include <stdlib.h>
#include <ctype.h>
#include "tokenizer.h"

Token getNextToken(const char* expression, int* index) {
    Token token;
    token.type = TOKEN_INVALID;
    token.value = 0.0;

    while (expression[*index] == ' ' || expression[*index] == '\t') {
        (*index)++;
    }

    char current = expression[*index];

    if (isdigit(current) || current == '.') {
        char buffer[64];
        int bufIndex = 0;

        while (isdigit(current) || current == '.') {
            if (bufIndex < 63) {
                buffer[bufIndex++] = current;
            }
            (*index)++;
            current = expression[*index];
        }
        buffer[bufIndex] = '\0';

        token.type = TOKEN_NUMBER;
        token.value = atof(buffer);

        return token;
    }

    switch (current) {
    case '+':
        token.type = TOKEN_PLUS;
        break;
    case '-':
        token.type = TOKEN_MINUS;
        break;
    case '*':
        token.type = TOKEN_MULTIPLY;
        break;
    case '/':
        token.type = TOKEN_DIVIDE;
        break;
    case '(':
        token.type = TOKEN_LPAREN;
        break;
    case ')':
        token.type = TOKEN_RPAREN;
        break;
    case '\0':
    case '\n':
        token.type = TOKEN_END;
        break;
    default:
        token.type = TOKEN_INVALID;
        break;
    }

    (*index)++;

    return token;
}