#include <stdio.h>
int mat[10][10], power_matrix[4][10][10], n;
void input();
void print();
void print_adjacent_list();
void copy();
void calculate_power_matrix();
void print_number_of_paths();

int main(void) {
    printf("\n");
    input();
    print_adjacent_list();
    printf("\n\n");
    copy();
    calculate_power_matrix();
    print_number_of_paths();
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
void print() {
    printf("\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

//Print the adjacent list of each node
void print_adjacent_list() {
    for(int i = 0; i < n; i++) {
        printf("\nThe adjacent nodes of %d are: ", i);
        for(int j = 0; j < n; j++) {
            if(mat[i][j] != 0)
            printf("%d ", j);
        }
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

//Print number of paths of different lenght between nodes
void print_number_of_paths() {
    for(int p = 0; p < 4; p++) {
        printf("\nAll paths of length %d: ", p+1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(power_matrix[p][i][j] != 0)
                printf("\nNumber of path(s) between %d and %d of lenght %d are: %d", i, j, p+1, power_matrix[p][i][j]);
                else printf("\nThere is no path between %d and %d of length %d", i, j, p+1);
            }
        }
        printf("\n\n");
    }
}
