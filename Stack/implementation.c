#include <stdio.h>
#define MAX 50
int stack[MAX], top = -1;
void push(int);
int pop();
int peek();
void display();
int main(void) {
    push(5);
    push(6);
    printf("\nThe contents of the stack are: ");
    display();
    printf("\n");
    pop();
    pop();
    printf("\nThe contents of the stack are: ");
    display();
    printf("\n");
    return 0;
}

void push(int item) {
    if(top == MAX-1) {
        printf("\nStack Overflow.\n");
    }
    else {
        top++;
        stack[top] = item;
    }
}
int pop() {
    if(top == -1) {
        printf("\nStack Underflow.\n");
        return -1;
    }
    else {
        int value = stack[top];
        top--;
        return value;
    }
}
int peek(){
    if(top == -1) {
        printf("\nThe stack is empty.\n");
        return -1;
    }
    else {
        return stack[top];
    }
}
void display() {
    if(top == -1) {
        printf("\nThe stack is empty.\n");
    }
    else {
        for(int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
