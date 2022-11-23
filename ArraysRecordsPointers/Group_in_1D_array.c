/* The input/output format of the program follows
    ***input***
    Enter number of groups: 3
    
    Enter the elements of group 1 (-1 to stop): 1 2 9 8 7 6 5 -1
    Enter the elements of group 2 (-1 to stop): 4 7 3 -1
    Enter the elements of group 3 (-1 to stop): 5 4 6 2 9 -1
    
    ***output***
    Enter which group you want to see: 2
    Group 2 is: 4 7 3
*/
#include <stdio.h>
int main(void)
{
    int g, k = 0, temp, array[100], count = 0;
    printf("\nEnter number of groups: ");
    scanf("%d", &g);
    int group[g], number[g];
    for(int i = 0; i < g; i++) {
        printf("\nEnter the elements of group %d (-1 to stop): ", i+1);
        group[i] = k; //Starting index of a group
        while(1) {
            scanf("%d", &temp);
            if(temp == -1) break;
            count++;
            array[k++] = temp;
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
