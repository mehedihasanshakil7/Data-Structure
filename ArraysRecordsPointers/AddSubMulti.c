#include <stdio.h>
void read_matrix(int mat[5][5], int);
void display_matrix(int mat[5][5], int);
void addition(int mat1[5][5], int mat2[5][5], int mat3[5][5], int);
void subtraction(int mat1[5][5], int mat2[5][5], int mat3[5][5], int);
void multiplication(int mat1[5][5], int mat2[5][5], int mat3[5][5], int);
int main(void)
{
    int n, mat1[5][5], mat2[5][5], mat3[5][5];
    printf("Enter size of sqaure matrix: ");
    scanf("%d", &n);
    read_matrix(mat1, n);
    read_matrix(mat2, n);
    addition(mat1, mat2, mat3, n);
    printf("The addition matrix is:\n");
    display_matrix(mat3, n);
    subtraction(mat1, mat2, mat3, n);
    printf("The subtraction matrix is:\n");
    display_matrix(mat3, n);
    multiplication(mat1, mat2, mat3, n);
    printf("The multiplication matrix is:\n");
    display_matrix(mat3, n);
    return 0;
}

void read_matrix(int mat[5][5], int n) {
    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void display_matrix(int mat[5][5], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void addition(int mat1[5][5], int mat2[5][5], int mat3[5][5], int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
void subtraction(int mat1[5][5], int mat2[5][5], int mat3[5][5], int n) {
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat3[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}
void multiplication(int mat1[5][5], int mat2[5][5], int mat3[5][5], int n) {
    int temp = 0;
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n;i ++) {
            for(int j = 0; j < n; j++) {
                temp += mat1[k][j]*mat2[j][i];
            }
            mat3[k][i] = temp;
            temp = 0;
        }
    }
}
