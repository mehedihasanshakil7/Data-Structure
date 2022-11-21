#include <stdio.h>
int fibonacci(int);
int main(void) {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("\nThe fibonacci series of first %d terms:\n", n);
    for(int i = 0; i < n; i++) {    //Print the series
        printf("%d ", fibonacci(i));
    }
    printf("\n\n");
    //printf("\nThe %d-th term of the series is %d\n\n", n, fibonacci(n - 1)); //Print only n-th term
    return 0;
}
int fibonacci(int n) {
    if(n == 0 || n == 1) {
        return n;
    }
    else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
