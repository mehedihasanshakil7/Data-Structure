/* The input/output format of the program follows
    Enter the row and column of the matrix: 3 4
    Enter the matrix:
    1 2 0 0
    4 7 3 0
    5 4 6 2
    1 9 0 0
    (The zero entries indicate that this cells are empty)
    Enter which group you want to see: 3
    Group 3 is: 5 4 6 2
*/
#include <stdio.h>
int main(void)
{
    int row, column, k = 0, temp, array[100], count = 0;
    printf("Enter the row and column of the matrix: ");
    scanf("%d%d", &row, &column);
    int group[row], number[row];
    printf("Enter the matrix:\n");
    for(int i = 0; i < row; i++) {
        group[i] = k; //Starting index of a group
        for(int j = 0; j < column; j++) {
            scanf("%d", &temp);
            if(temp != 0) {
                count++;
                array[k++] = temp;
            }
        }
        number[i] = count; //Number of elements in a group
        count = 0;
    }
    int show;
    printf("Enter which group you want to see: ");
    scanf("%d", &show);
    int start = group[show-1], end = start+number[show-1];
    printf("\nGroup %d is: ", show);
    for(int i = start; i < end; i++) {
        printf("%d ", array[i]);
    }
    puts("\n\n");
    return 0;
}
