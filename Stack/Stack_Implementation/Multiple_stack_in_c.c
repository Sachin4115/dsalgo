#include <stdio.h>

#define MAX_SIZE 100
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

void initialize (Stack *stack) {
    stack->top = -1;
}

void push (Stack *stack, int element) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack Overflow! Cannot push element %d\n", element);
        return;
    }
    stack->arr[++stack->top] = element;
}

int pop (Stack *stack) {
    if (stack->top == -1) {
        printf("Stack Underflow! Cannot pop element.\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

int peek (Stack *stack) {
    if (stack->top == -1) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->arr[stack->top];
}

int main () {
    Stack stack[10];
    for(int i=0;i<10;i++){
        initialize(&stack[i]);
    }

    push (&stack[0], 10);
    push (&stack[0], 20);
    push (&stack[0], 30);

    printf("Top element: %d\n", peek(&stack[0]));
    printf("Popped element: %d\n", pop(&stack[0]));
    printf("Top element after popping: %d\n", peek(&stack[0]));

    printf("-----------------------------------\n");

    push (&stack[1], 1);
    push (&stack[1], 2);
    push (&stack[1], 3);

    printf("Top element: %d\n", peek(&stack[1]));
    printf("Popped element: %d\n", pop(&stack[1]));
    printf("Top element after popping: %d\n", peek(&stack[1]));

    printf("-----------------------------------\n");

    printf("%d\t%d",peek(&stack[0]),peek(&stack[1]));

    return 0;
}