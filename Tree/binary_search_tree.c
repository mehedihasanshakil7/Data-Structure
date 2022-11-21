#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};
struct node *root = NULL, *ptr = NULL;
int isPrint = 1;
struct node* create_node(int);
void insert(int);
void print_tree(struct node*, int);
void print_inorder(struct node*);
int main(void) {
    int item;
    printf("Insert a node: ");
    scanf("%d", &item);
    while (item != -1)
    {
        insert(item);
        if(isPrint) {
            print_tree(root, 0);
        }
	printf("Insert a node (-1 to terminate insertion): ");
        scanf("%d", &item);
    }
    print_tree(root, 0);
    printf("Inorder traversal: ");
    print_inorder(root);
    printf("\n\n");
    return 0;
}

//Create node, assign value and return pointer
struct node* create_node(int item) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void insert(int item) {
    if(root == NULL) {
        root = create_node(item);
    }
    else {
        int loc = 1;
        ptr = root;
        while (1)
        {
            if(item < ptr->data) {
                if(ptr->left == NULL) {
                    ptr->left = create_node(item);
                    isPrint = 1;
                    break;
                }
                ptr = ptr->left;
                loc = loc * 2;
            }
            else if(item > ptr->data) {
                if(ptr->right == NULL) {
                    ptr->right = create_node(item);
                    isPrint = 1;
                    break;
                }
                ptr = ptr->right;
                loc = loc * 2 + 1;
            }
            else {
                printf("\nThe node %d is founded at position %d\n", item, loc);
                isPrint = 0;
                break;
            }
        }
        
    }
}

void print_tree(struct node *ptr1, int space) {
    int increase = 10;
    if(ptr1 == NULL) {
        return;
    }
    space = space + increase;
    print_tree(ptr1->right, space);
    printf("\n");
    for(int i = increase; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", ptr1->data);
    print_tree(ptr1->left, space);
}

void print_inorder(struct node *ptr1) {
    if(ptr1 == NULL) {
        return;
    }
    else {
        print_inorder(ptr1->left);
        printf("%d ", ptr1->data);
        print_inorder(ptr1->right);
    }
}
