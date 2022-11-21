#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 100
int top = 0;
double stack[MAX];
void push(double);
double pop();
double peek();

int main() {
    char p[100];
    puts("Enter the postfix expression: ");
    gets(p);
    int i = 0;
    double number, result;
    puts("\nThe expression is: ");
    puts(p);
    strcat(p, " )"); //Add " )" as a sentinel with a forward space
    while(p[i] != ')') {
        if(isdigit(p[i]) || p[i] == '.') {
            int k = 0;
            char snumber[10] = "";
            while(p[i] != ' ') { //Form the number as string
                snumber[k++] = p[i++];
            }
            sscanf(snumber, "%lf", &number); //String to integer number
            push(number);
        }
        else {
            double a, b;
            if(p[i] == '^') {
                a = pop();
                b = pop();
                push(pow(b, a));
            }
            else if(p[i] == '+') {
                a = pop();
                b = pop();
                 push(b+a);
            }
            else if(p[i] == '-') {
                a = pop();
                b = pop();
                 push(b-a);
            }
            else if(p[i] == '*') {
                a = pop();
                b = pop();
                 push(b*a);
            }
            else if(p[i] == '/') {
                a = pop();
                b = pop();
                 push(b/a);
            }
            i++;
        }
        i++;
    }
    printf("\nThe result is %.2lf\n\n", pop());
    return 0;
}
void push(double item) {
    if(top == MAX-1) {
        puts("\nStack Overflow\n");
    }
    else {
        top++;
        stack[top] = item;
    }
}
double pop() {
    if(top == -1) {
        puts("\nStack Underflow\n");
        return -1;
    }
    else {
        double value = stack[top];
        top--;
        return value;
    }
}
double peek() {
    if(top == -1) {
        puts("\nStack is empty\n");
        return -1;
    }
    else {
        return stack[top];
    }
}
