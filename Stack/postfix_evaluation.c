/* Input Output format
	Enter the postfix expression: A B - 3.9 + 3 / C ^
	Enter the value of A: 2.5
	Enter the value of B: .4
	Enter the value of D: 3
	The result is: 8.00

*/
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

int main()
{
	char p[100];
	puts("Enter the postfix expression: ");
	gets(p);
	int i = 0;
	double number, result;
	strcat(p, ")"); // Add ")" as a sentinel
	while (p[i] != ')')
	{
		if (isdigit(p[i]) || p[i] == '.')
		{
			int k = 0;
			char snumber[10] = "";
			while (isdigit(p[i]) || p[i] == '.') // Form the number as string
			{
				snumber[k++] = p[i++];
			}
			sscanf(snumber, "%lf", &number); // String to double number
			push(number);
			continue;
		}
		if ((p[i] >= 'A' && p[i] <= 'Z') || (p[i] >= 'a' && p[i] <= 'z'))
		{
			printf("\nEnter the value of %c: ", p[i]);
			double value;
			scanf("%lf", &value);
			push(value);
		}
		else if (p[i] != ' ')
		{
			double a, b;
			a = pop();
			b = pop();
			if (p[i] == '^')
			{
				push(pow(b, a));
			}
			else if (p[i] == '+')
			{
				push(b + a);
			}
			else if (p[i] == '-')
			{
				push(b - a);
			}
			else if (p[i] == '*')
			{
				push(b * a);
			}
			else if (p[i] == '/')
			{
				push(b / a);
			}
		}
		i++;
	}
	printf("\nThe result is %.2lf\n\n", pop());
	return 0;
}
void push(double item)
{
	if (top == MAX - 1)
	{
		puts("\nStack Overflow\n");
	}
	else
	{
		top++;
		stack[top] = item;
	}
}
double pop()
{
	if (top == -1)
	{
		puts("\nStack Underflow\n");
		return -1;
	}
	else
	{
		double value = stack[top];
		top--;
		return value;
	}
}
double peek()
{
	if (top == -1)
	{
		puts("\nStack is empty\n");
		return -1;
	}
	else
	{
		return stack[top];
	}
}
