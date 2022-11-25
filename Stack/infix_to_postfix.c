#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char);
char pop();
char peek();
int precedence(char);
int isEmpty();

int main()
{
    char infix[100], postfix[100];
    puts("\nEnter an expression:");
    gets(infix);
    strcat(infix, ")"); // Add ")" as sentinel
    push('(');
    int i = 0, k = 0;
    while (!isEmpty()) //Is stack empty?
    {
        if (infix[i] == ' ')
        {
            i++;
            continue;
        }
        else if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z'))
        {
            postfix[k++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push('(');
        }
        else if (infix[i] == ')')
        {
            while (peek() != '(')
            {
                postfix[k++] = pop(); // Pop all operators
            }
            pop(); // Pop "("
        }
        else
        {
            while (precedence(peek()) >= precedence(infix[i]))
            {
                postfix[k++] = pop(); // Operators of same or higher precedence are popped out
            }
            push(infix[i]); // Push the new operator to stack
        }
        i++;
    }
    postfix[k] = '\0';
    puts("\nThe postfix notation is:");
    puts(postfix);
    puts("\n");
    return 0;
}

void push(char ch)
{
    if (top == MAX - 1)
    {
        puts("\nStack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = ch;
    }
}
char pop()
{
    if (top == -1)
    {
        puts("\nStack Underflow\n");
        return '\0';
    }
    else
    {
        char ch1 = stack[top];
        top--;
        return ch1;
    }
}
char peek()
{
    if (top == -1)
    {
        puts("\nThe Stack is empty\n");
        return '\0';
    }
    else
    {
        return stack[top];
    }
}
int isEmpty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}
int precedence(char ch)
{
    switch (ch)
    {
    case '^':
        return 3;
    case '*':
        return 2;
    case '/':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    default:
        return 0;
    }
}
