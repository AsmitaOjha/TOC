#include <stdio.h>

#define MAX_STACK_SIZE 100

// Stack data structure
typedef struct {
    char data[MAX_STACK_SIZE];
    int top;
} Stack;

// Push an element onto the stack
void push(Stack *stack, char value) {
    if (stack->top < MAX_STACK_SIZE - 1) {
        stack->top++;
        stack->data[stack->top] = value;
    } else {
        printf("Stack Overflow\n");
    }
}

// Pop an element from the stack
char pop(Stack *stack) {
    if (stack->top >= 0) {
        char value = stack->data[stack->top];
        stack->top--;
        return value;
    } else {
        printf("Stack Underflow\n");
        return '\0';
    }
}

// Check if the stack is empty
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Pushdown Automaton for a^n b^n
int acceptString(char *input) {
    Stack stack;
    stack.top = -1;

    // Initial state
    push(&stack, 'Z');

    char symbol;
    while (*input != '\0') {
        symbol = *input;

        if (stack.data[stack.top] == 'Z' && symbol == 'a') {
            pop(&stack);
            push(&stack, 'X');
            input++;
        } else if (stack.data[stack.top] == 'X' && symbol == 'a') {
            push(&stack, 'X');
            input++;
        } else if (stack.data[stack.top] == 'X' && symbol == 'b') {
            pop(&stack);
            input++;
        } else {
            return 0;  // Rejected
        }
    }

    return isEmpty(&stack);  // Accepted if stack is empty
}

int main() {
    char input[100];

    printf("Enter a string: ");
    scanf("%s", input);

    if (acceptString(input)) {
        printf("Accepted\n");
    } else {
        printf("Rejected\n");
    }

    return 0;
}
