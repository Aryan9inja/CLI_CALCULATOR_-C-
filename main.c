#include <stdio.h>
#include "parser.h"

const char* tokenTypeToString(TokenType type) {
    switch (type) {
    case TOKEN_NUMBER: return "NUMBER";
    case TOKEN_PLUS: return "+";
    case TOKEN_MINUS: return "-";
    case TOKEN_MULTIPLY: return "*";
    case TOKEN_DIVIDE: return "/";
    case TOKEN_LPAREN: return "(";
    case TOKEN_RPAREN: return ")";
    case TOKEN_END: return "END";
    default: return "UNKNOWN";
    }
}

void printPostfix(TokenArray* postfix) {
    printf("Postfix expression:\n");
    for (int i = 0; i < postfix->size; ++i) {
        Token tok = postfix->tokens[i];
        if (tok.type == TOKEN_NUMBER)
            printf("%.2f ", tok.value);
        else
            printf("%s ", tokenTypeToString(tok.type));
    }
    printf("\n");
}

int main() {
    char expression[20];
    printf("Enter an expression");
    fgets(expression,sizeof(expression),stdin);

    printf("Infix expression: %s\n", expression);

    TokenArray* postfix = infixToPostfix(expression);
    printPostfix(postfix);

    freeTokenArray(postfix);
    return 0;
}

