#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node *start = NULL, *ptr = NULL;
void create_linked_list();
struct node* create_node(int);
void delete_beginning_node();
void delete_end_node();
void delete_last_node();
void delete_given_node();
void display_linked_list();
int main(void) {
    create_linked_list();
    printf("\nList before deletion: ");
    display_linked_list();
    //delete_beginning_node();
    //delete_last_node();
    delete_given_node();
    printf("\nList after deletion: ");
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
//Delete the beginnig node from the list
void delete_beginning_node() {
    struct node *temp = start;
    start = start->next;
    printf("\nThe deleted node is: %d\n", temp->data);
    free(temp);
}

//Delete the last node from the list
void delete_last_node() {
    struct node *temp, *ptrp;
    ptr = start; ptrp = start;
    while (ptr->next != NULL) {
        ptrp = ptr;
        ptr = ptr->next;
    }    
     temp = ptr;
     ptrp->next = NULL;
     printf("The deleted node is: %d\n", temp->data);
     free(temp);
}

//Delete a given node
void delete_given_node() {
    struct node *temp, *ptrp;
    ptr = start; ptrp = start;
    int item;
    printf("Enter a node to be deleted: ");
    scanf("%d", &item);
    while (ptr->data != item && ptr->next != NULL)
    {
        ptrp = ptr;
        ptr = ptr->next;
    }
    if(ptr == start && ptrp == start) { //Deleting 1st node
        temp = start;
        start = start->next;
        printf("\nThe node %d is deleted\n", temp->data);
        free(temp);
    }
    else if(ptr->next == NULL && ptr->data == item) { //Deleting last node
        temp = ptr;
        ptrp->next = NULL;
        printf("\nThe node %d is deleted\n", temp->data);
        free(temp);
    }
    else if(ptr->next != NULL) {
        temp = ptr;
        ptrp->next = ptr->next;
        printf("\nThe node %d is deleted\n", temp->data);
        free(temp);
    }
    else {
        printf("\nThe node %d is not founded in the list\n", item);
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
