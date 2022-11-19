#include <stdio.h>
int mat[10][10], power_matrix[4][10][10], n, Br[10][10], p[10][10];
void input();
void print(int[10][10]);
void copy();
void calculate_power_matrix();
void create_all_path_matrix();
void create_path_matrix();
int is_strong();

int main(void) {
    printf("\n");
    input();
    copy();
    calculate_power_matrix();
    create_all_path_matrix();
    create_path_matrix();
    printf("\n\nBr:");
    print(Br);
    printf("\nPath matrix:");
    print(p);
    if(is_strong()) printf("\nThe graph is strongly conected\n\n");
    else printf("\nThe graph is not connected strongly\n\n");
    return 0;
}

//Take input from keyboard
void input() {
    printf("\nEnter number of nodes: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

//Print the matrix
void print(int matrix[10][10]) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


//Copy adjacency matrix to the first page of power matrix
void copy() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            power_matrix[0][i][j] = mat[i][j];
        }
    }
}

//Calculate the power matrices
void calculate_power_matrix() {
    int temp = 0;
    for(int p = 0; p < 3; p++) {
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    temp += power_matrix[p][k][j] * mat[j][i];
                }
                power_matrix[p+1][k][i] = temp;
                temp = 0;
            }
        }
    }
}

//Determine path matrix from power matrix
void create_all_path_matrix() {
    for(int p = 0; p < 4; p++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                Br[i][j] += power_matrix[p][i][j];
            }
        }
    }
}

//Determine path matrix which contains 0 and 1 only
void create_path_matrix() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(Br[i][j]) p[i][j] = 1;
        }
    }
}

//Check connectivity of the adjacency matrix
int is_strong() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(p[i][j] == 0) return 0;
        }
    }
    return 1;
}
