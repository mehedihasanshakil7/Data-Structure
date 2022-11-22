#include <stdio.h>
#define MAX 5
int queue[MAX], front = -1, rear = -1;
void push(int);
int pop();
int peek();
void display();
int main(void) {
    display();
    push(5);
    push(9);
    push(10);
    push(11);
    push(12);
    push(19);
    display();
    printf("\n\n");
    printf("\nThe deleted item is: %d\n\n", pop());
    printf("\nThe deleted item is: %d\n\n", pop());
    display();
    printf("\n\n");
    return 0;
}

//Push item end of the queue
void push(int item) {
    if(front == 0 && rear == MAX-1 || front == rear+1) {
        printf("\nQueue Overflow\n");
    }
    else if(front == -1 && rear == -1) {
        front = 0; rear = 0;
        queue[rear] = item;
    }
    else if (rear == MAX-1) {
        rear = 0;
        queue[rear] = item;
    }
    else {
        rear++;
        queue[rear] = item;
    }
}

//Pop the front element of the Queue and return the value
int pop() {
    if(front == -1 && rear == -1) {
        printf("\nQueue Underflow\n");
        return -1;
    }
    int value;
    value = queue[front];
    if(front == rear) {
        front = -1; rear = -1;
    }
    else {
        if(front == MAX-1) front = 0;
        else front++;
    }
    return value;
}

//Return the front element without deleting it
int peek() {
    if(front == -1 && rear == -1) {
        printf("\nQueue Underflow\n");
        return -1;
    }
    else {
        return queue[front];
    }
}

//Display the queue
void display() {
    if(front == -1 && rear == -1) {
        printf("\nThe Queue is empty\n");
    }
    else {
        printf("\nThe contents of the queue are: ");
        if(front <= rear) {
            for(int i = front; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
        else {
            for(int i = front; i < MAX; i++) {
                printf("%d ", queue[i]);
            }
            for(int i = 0; i <= rear; i++) {
                printf("%d ", queue[i]);
            }
        }
    }
}
