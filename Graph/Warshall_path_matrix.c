#include <stdio.h>
int mat[10][10], p[10][10], n;
void input();
void copy();
void warshall();
void display();
int is_strong();
int main(void) {
    input();
    copy();
    warshall();
    printf("\nThe path matrix is:\n");
    display();
    if(is_strong()) printf("\nThe graph is strongly connected\n\n");
    else printf("\nThe graph is not strongly connected\n\n");
    return 0;
}

//Take input as matrix from keyboard
void input() {
    printf("\nEnter number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matric:\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

//Copy the adjacency matrix to the path matrix
void copy() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            p[i][j] = mat[i][j];
        }
    }
}

//Determine the path matrix using warshall algorithm
void warshall() {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                p[i][j] = p[i][j] || (p[i][k] && p[k][j]);
            }
        }
    }
}

//Dispaly matrix
void display() {
    for(int  i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", p[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//Check the connectivity of the path matrix
int is_strong() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(p[i][j] == 0) return 0;
        }
    }
    return 1;
}
