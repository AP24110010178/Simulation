#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Stack structure
struct Stack {
    int arr[MAX];
    int top;
};

// Function prototypes
void initialize(struct Stack *s);
int isFull(struct Stack *s);
int isEmpty(struct Stack *s);
void push(struct Stack *s, int value);
int pop(struct Stack *s);
int peek(struct Stack *s);
void display(struct Stack *s);

int main() {
    struct Stack s;
    initialize(&s);

    int choice, value;

    while (1) {
        printf("\n========= STACK SIMULATION MENU =========\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek (Top Element)\n");
        printf("4. Display Stack\n");
        printf("5. Check if Stack is Full\n");
        printf("6. Check if Stack is Empty\n");
        printf("7. Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(&s, value);
            break;

        case 2:
            value = pop(&s);
            if (value != -1)
                printf("Popped: %d\n", value);
            break;

        case 3:
            value = peek(&s);
            if (value != -1)
                printf("Top element: %d\n", value);
            break;

        case 4:
            display(&s);
            break;

        case 5:
            if (isFull(&s))
                printf("Stack is FULL\n");
            else
                printf("Stack is NOT full\n");
            break;

        case 6:
            if (isEmpty(&s))
                printf("Stack is EMPTY\n");
            else
                printf("Stack is NOT empty\n");
            break;

        case 7:
            printf("Exiting program...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

// Initialize stack
void initialize(struct Stack *s) {
    s->top = -1;
}

// Check full
int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

// Check empty
int isEmpty(struct Stack *s) {
    return s->top == -1;
}

// Push
void push(struct Stack *s, int value) {
    if (isFull(s)) {
        printf("Error: Stack Overflow! Cannot push %d\n", value);
        return;
    }
    s->arr[++(s->top)] = value;
    printf("%d pushed into stack\n", value);
}

// Pop
int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Error: Stack Underflow! Cannot pop\n");
        return -1;
    }
    return s->arr[(s->top)--];
}

// Peek
int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty — no top element.\n");
        return -1;
    }
    return s->arr[s->top];
}

// Display
void display(struct Stack *s) {
    int i;  // DECLARED HERE, OUTSIDE LOOP

    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return;
    }

    printf("Stack elements: ");
    for (i = 0; i <= s->top; i++) {  // USING i HERE
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}
