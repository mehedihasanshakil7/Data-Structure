#include <stdio.h>
#include <string.h>
void merge_sorted_integer_array();
void merge_sorted_char_array();
void print_integer_array(int[], int);
void print_character_array(char[], int);

int main(void)
{
    merge_sorted_integer_array();
    merge_sorted_char_array();
    printf("\n");
    return 0;
}

// Merge two integer type sorted arrays
void merge_sorted_integer_array()
{
    int i = 0, j = 0, k = 0;
    int len_a1 = 5, a1[5] = {10, 20, 46, 57, 77};
    int len_a2 = 7, a2[7] = {12, 45, 58, 76, 81, 88, 99};
    int len_a3 = len_a1 + len_a2, a3[15];
    printf("\nFirst array: ");
    print_integer_array(a1, len_a1);
    printf("\nSecond array: ");
    print_integer_array(a2, len_a2);
    while (k < len_a3)
    {
        if (i >= len_a1 && j < len_a2) //Checking if a1 is running out
        {
            a3[k++] = a2[j++];
        }
        else if (j >= len_a2 && i < len_a1) //Checking if a2 is running out
        {
            a3[k++] = a1[i++];
        }
        else
        {
            if (a1[i] <= a2[j])
            {
                a3[k++] = a1[i++];
            }
            else
            {
                a3[k++] = a2[j++];
            }
        }
    }
    printf("\nMerged integer array: ");
    print_integer_array(a3, len_a3);
}

//Merge two char type arrays
void merge_sorted_char_array() {
    int i = 0, j = 0, k = 0, len_a1 = 5, len_a2 = 7;
    char a1[5] = {'a', 'e', 'i', 'o', 'u'};
    char a2[7] = {'a', 'a', 'i', 'k', 'n', 'r', 't'};
    int len_a3 = len_a1 + len_a2;
    char a3[15];
    printf("\n\nFirst array: ");
    print_character_array(a1, len_a1);
    printf("\nSecond array: ");
    print_character_array(a2, len_a2);
    while (k < len_a3)
    {
        if (i >= len_a1 && j < len_a2) //Checking if a1 is running out
        {
            a3[k++] = a2[j++];
        }
        else if (j >= len_a2 && i < len_a1) //Checking if a2 is running out
        {
            a3[k++] = a1[i++];
        }
        else
        {
            if (a1[i] <= a2[j])
            {
                a3[k++] = a1[i++];
            }
            else
            {
                a3[k++] = a2[j++];
            }
        }
    }
    printf("\nMerged character array: ");
    print_character_array(a3, len_a3);
}

//Print integer array
void print_integer_array(int a[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

//Print character array
void print_character_array(char a[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("%c ", a[i]);
    }
    printf("\n");
}
