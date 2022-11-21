#include <stdio.h>
void move(int, char[], char[], char[]);
int main(void) {
    int n;
    printf("\nEnter number of disks: ");
    scanf("%d", &n);
    printf("\n");
    move(n, "beg", "aux", "end");
    printf("\n");
    return 0;
}
void move(int n, char beg[], char aux[], char end[]) {
    if(n == 1) {
        printf("Move from %s to %s\n", beg, end);
    }
    else {
        move(n-1, beg, end, aux);
        move(1, beg, aux, end);
        move(n-1, aux, beg, end);
    }
}
