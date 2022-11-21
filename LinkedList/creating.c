#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *start = NULL, *ptr = NULL;
struct node* create_node(int);
void create_linked_list();
void display_linked_list();
int main(void) {
    create_linked_list();
    display_linked_list();
    return 0;
}
struct node* create_node(int info) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = info;
    new_node->next = NULL;
    return new_node;
}
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
void display_linked_list() {
    ptr = start;
    printf("\nThe linked list is: ");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n\n");
}
