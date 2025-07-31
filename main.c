#include "tokenizer.h"
#include <stdio.h>

const char* tokenTypeToString(TokenType type) {
    switch (type) {
        case TOKEN_NUMBER: return "NUMBER";
        case TOKEN_PLUS: return "PLUS";
        case TOKEN_MINUS: return "MINUS";
        case TOKEN_MULTIPLY: return "MULTIPLY";
        case TOKEN_DIVIDE: return "DIVIDE";
        case TOKEN_LPAREN: return "LPAREN";
        case TOKEN_RPAREN: return "RPAREN";
        case TOKEN_END: return "END";
        default: return "INVALID";
    }
}

int main() {
    char input[256];
    printf("Enter expression: ");
    fgets(input, sizeof(input), stdin);

    int index = 0;
    Token tok;
    do {
        tok = getNextToken(input, &index);
        printf("[%s", tokenTypeToString(tok.type));
        if (tok.type == TOKEN_NUMBER) {
            printf(": %.2f", tok.value);
        }
        printf("]\n");
    } while (tok.type != TOKEN_END && tok.type != TOKEN_INVALID);

    return 0;
}
