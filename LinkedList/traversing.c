#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1416
struct node {
    int data;
    struct node *next;
};

struct node* create_node(int);
void create_linked_list();
struct node *start = NULL, *ptr = NULL;

int main() {
    create_linked_list();
    int total = 0, max = start->data, min = start->data;
    int temp, n = 0;
    double radian = PI / 180.0;
    ptr = start;
    while(ptr != NULL) {
        temp = ptr->data;
        printf("sin(%d') = %.2f\n", temp, sin(temp * radian));
        if(temp > max) max = temp;
        else if(temp < min) min = temp;
        total += temp;
        n++;
        ptr = ptr->next;
    }
    printf("\nMaximum = %d\n", max);
    printf("Minimum = %d\n", min);
    printf("Average = %.2f\n\n", total / (float)n);
    return 0;
}

//Create node, assign value and return a pointer
struct node* create_node(int info) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = info;
    new_node->next = NULL;
    return new_node;
}

//Create the linked list
void create_linked_list() {
    int temp;
    struct node *new_node = NULL;
    printf("\nEnter the elements of linked list (-1 to terminate insertion):\n");
    while(1) {
        scanf("%d", &temp);
        if(temp == -1) break;
        new_node = create_node(temp);
        if(start == NULL) {
            start = new_node;
            ptr = start;
        }
        else {
            ptr->next = new_node;
            ptr = ptr->next;
        }
    }
}

//Display the linked list
/*void display_linked_list() {
    ptr = start;
    printf("\nThe linked list is: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}*/
