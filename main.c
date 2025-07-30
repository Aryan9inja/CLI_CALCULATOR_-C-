#include "stack.h"
#include <stdio.h>

int main() {
    Stack* s = createStack(10);
    push(s, 10.0);
    push(s, 20.0);
    printf("Top: %.2f\n", peek(s));  // 20.00
    printf("Popped: %.2f\n", pop(s)); // 20.00
    printf("Top after pop: %.2f\n", peek(s)); // 10.00
    freeStack(s);
    return 0;
}
