#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 100
int stk[MAX];
int top = -1;
void push(int);
int pop();
int main(void) {
    printf("\nEnter the postfix expression: ");
    char p[MAX];
    gets(p);
    strcat(p, ")"); // ")" is a sentinel
    for(int i = 0; p[i] != ')'; i++) {
        if(isdigit(p[i])) {
            push(p[i] - '0');
        }
        else if((p[i] >= 'A' && p[i] <= 'Z') || (p[i] >= 'a' && p[i] <= 'z')) {
            printf("\nEnter value of %c: ", p[i]);
            int value;
            scanf("%d", &value);
            push(value);
        }
        else if(p[i] == '+' || p[i] == '-' || p[i] == '*' || p[i] == '/' || p[i] == '^') {
            int a = pop();
            int b = pop();
            if(p[i] == '+') {
                push(b + a);
            }
            else if(p[i] == '-') {
                push(b - a);
            }
            else if(p[i] == '*') {
                push(b * a);
            }
            else if(p[i] == '/') {
                push(b / a);
            }
            else {
                push(pow(b, a));
            }
        }
    }
    printf("\nEvaluation of postfix is: %d\n\n", pop());
    return 0;
}

void push(int info) {
    if(top == MAX - 1) {
        printf("\nStack Overflow\n");
    }
    else {
        stk[++top] = info;
    }
}
int pop() {
    if(top == -1) {
        return -1;
    }
    else {
        return stk[top--];
    }
}
