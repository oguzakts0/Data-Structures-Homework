#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack yapýsý (operatörler için)
typedef struct {
    char data[MAX];
    int top;
} Stack;

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->data[++s->top] = c;
    }
}

char pop(Stack *s) {
    if (s->top >= 0) {
        return s->data[s->top--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (s->top >= 0) {
        return s->data[s->top];
    }
    return '\0';
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

// Operatör öncelikleri
int precedence(char op) {
    switch (op) {
        case '^': return 4;
        case '*':
        case '/': return 3;
        case '+':
        case '-': return 2;
        default: return 0;
    }
}

// Saðdan mý sola mý iliþkilidir
int isRightAssociative(char op) {
    return op == '^'; // üs iþlemi saðdan iliþkilidir
}

int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

void shuntingYard(const char *expr, char *output) {
    Stack stack;
    stack.top = -1;
    int j = 0;

    for (int i = 0; expr[i] != '\0'; i++) {
        char token = expr[i];

        if (isspace(token)) continue; // boþluklarý atla

        if (isdigit(token)) {
            // Sayý ise direkt output’a yaz
            output[j++] = token;
        }
        else if (isOperator(token)) {
            while (!isEmpty(&stack) && isOperator(peek(&stack)) &&
                  ((precedence(peek(&stack)) > precedence(token)) ||
                   (precedence(peek(&stack)) == precedence(token) && !isRightAssociative(token)))) {
                output[j++] = pop(&stack);
            }
            push(&stack, token);
        }
        else if (token == '(') {
            push(&stack, token);
        }
        else if (token == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                output[j++] = pop(&stack);
            }
            if (!isEmpty(&stack) && peek(&stack) == '(') {
                pop(&stack); // '(' i at
            }
        }
    }

    // stack'te kalanlarý output’a yaz
    while (!isEmpty(&stack)) {
        output[j++] = pop(&stack);
    }
    output[j] = '\0';
}

int main() {
    char expr[MAX];
    char output[MAX];

    printf("Infix ifadeyi giriniz: ");
    fgets(expr, MAX, stdin);
    expr[strcspn(expr, "\n")] = '\0'; // newline temizle

    shuntingYard(expr, output);

    printf("Postfix ifade: %s\n", output);

    return 0;
}
