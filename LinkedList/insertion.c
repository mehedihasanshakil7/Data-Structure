#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};

void create_linked_list();
struct node* create_node(int);
void display_linked_list();
void insert_beginning(int);
void insert_end(int);
void insert_after_given_node(int);
void insert_sorted_list(int);
struct node *start = NULL, *ptr = NULL;

int main(void) {
    int item;
    create_linked_list();
    printf("\nBefore insertion: ");
    display_linked_list();
    printf("Enter a number: ");
    scanf("%d", &item);
    insert_beginning(item);
    //insert_end(item);
    //insert_after_given_node(item);
    //insert_sorted_list(item);
    printf("\nAfter insertion: ");
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
    printf("\nEnter the elements of linked list(-1 to terminate insertion):\n");
    while (1)
     {
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

//Insert a node beginning of the list
void insert_beginning(int info) {
    struct node *temp = create_node(info);
    temp->next = start;
    start = temp;

}

//Insert a node end of the list
void insert_end(int info) {
    struct node *temp = create_node(info);
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    
}

//Insert a node after a given node
void insert_after_given_node(int info) {
    int given_node;
    printf("Enter a node after which you want to insert %d: ", info);
    scanf("%d", &given_node);
    struct node *ptrp, *temp = create_node(info);
    ptr = start, ptrp = start;
    while (ptr != NULL)
    {
        if(ptr->data == given_node) {
            ptrp = ptr;
            ptr = ptr->next;
            break;
        }
        ptrp = ptr;
        ptr = ptr->next;
    }
    temp->next = ptr;
    ptrp->next = temp;
}

//Insert a node into a sorted list
void insert_sorted_list(int info) {
    struct node *ptrp, *temp = create_node(info);
    ptr = start; ptrp = ptr;
    while (ptr != NULL)
    {
        if(ptr->data >= info) {
            break;
        }
        ptrp = ptr;
        ptr = ptr->next;
    }
    if(ptrp == start && ptr == start) {
        temp->next = start;
        start = temp;
    }
    else {
        temp->next = ptr;
        ptrp->next = temp;
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
