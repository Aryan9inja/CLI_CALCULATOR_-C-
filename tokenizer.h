#ifndef TOKENIZER_H
#define TOKENIZER_H

typedef enum {
    TOKEN_NUMBER,
    TOKEN_PLUS,
    TOKEN_MINUS,
    TOKEN_MULTIPLY,
    TOKEN_DIVIDE,
    TOKEN_LPAREN,
    TOKEN_RPAREN,
    TOKEN_END,
    TOKEN_INVALID
}TokenType;

typedef struct {
    TokenType type;
    double value;
}Token;

Token getNextToken(const char* expression, int* index);

#endif