#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

// Stack for characters
char stack[MAX];
int top = -1;

// Stack for operators and operands
void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = item;
    }
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}

// Function to check if character is operator
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Function to check precedence of operators
int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

// Function to convert Infix to Postfix
void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    for (i = 0; i < strlen(infix); i++) {
        char ch = infix[i];

        // If operand, add to postfix expression
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            push(ch);
        }
        // If ')', pop and add to postfix until '(' is found
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            pop(); // Remove '(' from stack
        }
        // If operator, pop operators of higher or equal precedence, then push
        else if (isOperator(ch)) {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // Pop all remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; // Null-terminate postfix expression
}

// Function to reverse a string
void reverse(char *exp) {
    int len = strlen(exp);
    for (int i = 0; i < len / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[len - i - 1];
        exp[len - i - 1] = temp;
    }
}

// Function to convert Infix to Prefix
void infixToPrefix(char infix[], char prefix[]) {
    // Reverse infix expression
    reverse(infix);

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < strlen(infix); i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    // Convert modified infix to postfix
    infixToPostfix(infix, prefix);

    // Reverse postfix to get prefix
    reverse(prefix);
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    infixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);

    return 0;
}