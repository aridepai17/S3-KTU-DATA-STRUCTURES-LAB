#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define SIZE 100

// Stack structure for characters
char charStack[SIZE];
int charTop;

// Stack structure for integers
int intStack[SIZE];
int intTop;

// Function to initialize the character stack
void initializeCharStack() {
    charTop = -1;
}

// Function to initialize the integer stack
void initializeIntStack() {
    intTop = -1;
}

// Function to push a character onto the stack
void pushChar(char c) {
    if (charTop == SIZE - 1) {
        printf("Character Stack Overflow\n");
        exit(1);
    }
    charStack[++charTop] = c;
}

// Function to pop a character from the stack
char popChar() {
    if (charTop == -1) {
        printf("Character Stack Underflow\n");
        exit(1);
    }
    return charStack[charTop--];
}

// Function to push an integer onto the stack
void pushInt(int value) {
    if (intTop == SIZE - 1) {
        printf("Integer Stack Overflow\n");
        exit(1);
    }
    intStack[++intTop] = value;
}

// Function to pop an integer from the stack
int popInt() {
    if (intTop == -1) {
        printf("Integer Stack Underflow\n");
        exit(1);
    }
    return intStack[intTop--];
}

// Function to get the precedence of operators
int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else {
        return -1;
    }
}

// Function to convert infix expression to postfix
void infixToPostfix(const char *infix, char *postfix) {
    initializeCharStack();
    int k = 0;
    char c;

    for (int i = 0; infix[i] != '\0'; i++) {
        if (isdigit(infix[i]) || isalpha(infix[i])) {
            postfix[k++] = infix[i];
        } else if (infix[i] == '(') {
            pushChar(infix[i]);
        } else if (infix[i] == ')') {
            while ((c = popChar()) != '(') {
                postfix[k++] = c;
            }
        } else { // Operator
            while (charTop != -1 && precedence(charStack[charTop]) >= precedence(infix[i])) {
                postfix[k++] = popChar();
            }
            pushChar(infix[i]);
        }
    }

    while (charTop != -1) {
        postfix[k++] = popChar();
    }
    postfix[k] = '\0'; // Null-terminate the postfix expression
}

// Function to get the value of a variable
int getVariableValue(char var) {
    int value;
    printf("Enter the value for %c: ", var);
    scanf("%d", &value);
    return value;
}

// Function to evaluate a postfix expression with variable substitution
int evaluatePostfix(const char *postfix) {
    initializeIntStack();
    int i = 0;
    int num1, num2, result;

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            int num = 0;
            // Handle multi-digit numbers
            while (isdigit(postfix[i])) {
                num = num * 10 + (postfix[i] - '0');
                i++;
            }
            pushInt(num);
            // Continue to the next character after the number
            continue;
        } else if (isalpha(postfix[i])) {
            // Handle variables
            int value = getVariableValue(postfix[i]);
            pushInt(value);
        } else {
            num2 = popInt();
            num1 = popInt();
            switch (postfix[i]) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/': result = num1 / num2; break;
                default:
                    printf("Invalid operator: %c\n", postfix[i]);
                    exit(1);
            }
            pushInt(result);
        }
        i++;
    }

    return popInt();
}

int main() {
    char infix[SIZE], postfix[SIZE];
    
    printf("Enter the infix expression: ");
    scanf("%s", infix);

    // Convert infix to postfix
    infixToPostfix(infix, postfix);
    printf("The corresponding postfix expression is: %s\n", postfix);

    // Evaluate the postfix expression
    int result = evaluatePostfix(postfix);
    printf("The result of postfix evaluation is: %d\n", result);

    return 0;
}