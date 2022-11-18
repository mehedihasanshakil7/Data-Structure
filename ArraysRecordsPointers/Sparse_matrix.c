/* A 3x3 sparse matrix looks like
   2
   4 5
   8 7 4
*/
#include <stdio.h>
int main(void) {
    int n, array[100];
    printf("Enter the size if sparse matrix(row only): ");
    scanf("%d", &n);
    int array_size = (n * (n + 1)) / 2;
    printf("Enter the sparse matrix:\n");
    for(int i = 0; i < array_size; i++) {
        scanf("%d", &array[i]);
    }
    
    //Print the element at specific location
    int index = 0, row, column;
    printf("Enter your desired row and column: ");
    scanf("%d%d", &row, &column);
    printf("\nThe element at [%d, %d] is: ", row, column);
    printf("%d\n", array[(row * (row-1)) / 2 + (column-1)]);

    //Print the whole sparse matrix
    printf("The sparse matrix is:\n");
    for(int k = 0; k < n; k++) {
        for(int j = 0; j < k + 1; j++) {
            printf("%d ", array[index++]);
        }
        printf("\n");
    }
    return 0;
}
