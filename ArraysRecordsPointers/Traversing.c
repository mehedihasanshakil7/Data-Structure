#include<stdio.h>
#include<math.h>

#define PI 3.1416

int main(void) {
    int i, n = 10, array[10] = {5, 30, 2, 6, 90, 1, 4, 9, 7, 8};
    int total = 0, maximum = array[0], minimum = array[0];
    double average;
    double radian = PI / 180; //sin() takes value as radian

    for(i = 0; i < n; i++) {
        printf("sin(%d') = %.2f\n", array[i], sin(array[i] * radian));
        total = total + array[i];
        if(array[i] > maximum) maximum = array[i];
        else if(array[i] < minimum) minimum = array[i];
    }
    average = total / 10.0;
    printf("Total = %d\n", total);
    printf("Average = %.2f\n", average);
    printf("Maximum = %d\n", maximum);
    printf("Minimum = %d\n", minimum);
    return 0;
}
