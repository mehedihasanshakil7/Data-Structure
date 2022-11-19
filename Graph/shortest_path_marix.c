#include <stdio.h>
#define INFINITY 99999
int mat[10][10], s[10][10], n;
void input();
void copy();
void warshall();
int min(int, int);
void display();
int main() {
    input();
    copy();
    warshall();
    printf("\n\nThe shortest path matrix is:\n");
    display();
    printf("\n");
    return 0;
}

//Take input from keyboard as adjacency matrix
void input() {
    printf("\nEnter the size of the matrix: ");
    scanf("%d", &n);
    printf("\nEnter the matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

//Copy the weighted matrix to the shortest path matrix
//Put infinity (large number) instead of 0
void copy() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(mat[i][j] != 0) s[i][j] = mat[i][j];
            else s[i][j] = INFINITY;
        }
    }
}

//Calculate the shortest path matrix by warshall algorithm
void warshall() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                s[i][j] = min(s[i][j], (s[i][k]+s[k][j]));
            }
        }
    }
}

//Returns the samller one of two value
int min(int a, int b) {
    return a < b ? a : b;
}

//Display the shortest path matrix
void display() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", s[i][j]);
        }
        printf("\n");
    }
}
