#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Define the structure of a stack
struct Stack {
    int data[MAX_SIZE];
    int top;
};

// Function prototypes
void initializeStack(struct Stack *stack);
void push(struct Stack *stack, int element);
int pop(struct Stack *stack);
int peek(struct Stack *stack);

int main() {
    struct Stack stack;
    initializeStack(&stack);

    // Push elements onto the stack
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Display the top element of the stack
    printf("Top element of the stack: %d\n", peek(&stack));

    // Pop elements from the stack
    printf("Popped element: %d\n", pop(&stack));
    printf("Popped element: %d\n", pop(&stack));

    // Display the top element of the stack after popping
    printf("Top element of the stack: %d\n", peek(&stack));

    return 0;
}

// Function to initialize the stack
void initializeStack(struct Stack *stack) {
    stack->top = -1;  // Initialize top to -1 to indicate an empty stack
}

// Function to push an element onto the stack
void push(struct Stack *stack, int element) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = element;  // Increment top and then push the element
}

// Function to pop an element from the stack
int pop(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack->data[stack->top--];  // Pop the element and then decrement top
}

// Function to return the top element of the stack
int peek(struct Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top];  // Return the element at the top of the stack
}

