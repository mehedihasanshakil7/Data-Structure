#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *start = NULL, *ptr = NULL;
void create_linked_list();
struct node* create_node(int);
void display_linked_list();
void sort_linked_list();
int main(void) {
    create_linked_list();
    printf("\nList before sorting: ");
    display_linked_list();
    sort_linked_list();
    printf("\nList after sorting: ");
    display_linked_list();
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

//Sort linked list without swaping values only
//Swap nodes
void sort_linked_list() {
    struct node *ptrpp = start, *temp, *ptrp, *end = NULL;
    while (end != start->next)
    {
        ptrp = start; ptr = start->next;
        while (ptr != end)
        {
            if(ptrp->data > ptr->data) {
                if(ptrp == start && ptr == start->next)
                {
                    temp = ptr->next; //Swapping first two elements
                    start = ptr;
                    ptr->next = ptrp;
                    ptrp->next = temp;
                }
                else{ //Swapping rest of the elements
                temp = ptr->next;
                ptr->next = ptrp;
                ptrp->next = temp;
                ptrpp->next = ptr;
                }
            }
            ptrpp = ptrp;
            ptrp = ptr;
            ptr = ptr->next;
        }
        end = ptrp;
    }
    
}

//Display the linked list
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
