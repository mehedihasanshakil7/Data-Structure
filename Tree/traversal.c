#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    int status;
    struct node *left;
    struct node *right;
};
struct node *create_node(int);
struct node *root = NULL, *ptr = NULL;
struct node *stk[100];
int first = 1, top = -1;
void push(struct node *);
struct node *pop();
struct node *peek();
int isEmpty();
struct node *create_tree();
void print_postorder();
void print_inorder();
void print_preorder();
void print_tree(struct node *, int);
int main(void)
{
    root = create_tree();
    printf("\nPrinted the tree hrizontally:\n");
    print_tree(root, 0);
    // printf("\nPostorder traversal: ");
    print_postorder();
    // printf("\nInorder traversal: ");
    // print_inorder();
    // printf("\nPreorder traversal: ");
    // print_preorder();
    return 0;
}

// Create tree taking input from keyboard
struct node *create_tree()
{
    int item;
    if (first)
    {
        printf("\nEnter root node: ");
        first = 0;
    }
    scanf("%d", &item);
    if (item == -1)
    {
        return NULL;
    }
    struct node *temp = create_node(item);
    printf("\nEnter left child of %d: ", temp->data);
    temp->left = create_tree();
    printf("\nEnter right child of %d: ", temp->data);
    temp->right = create_tree();
    return temp;
}

// Create node and return pointer
struct node *create_node(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->status = 1;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Iterative process
void print_postorder()
{
    if (root == NULL)
    {
        printf("\nThe tree is empty\n");
        return;
    }
    ptr = root;
    push(NULL); // Sentinel
    while (ptr != NULL)
    {
        push(ptr);
        if (ptr->right != NULL)
        {
            push(ptr->right);
            ptr->right->status = -1;
        }
        ptr = ptr->left;
        if (ptr == NULL)
        {
            ptr = pop();
            while (ptr->status == 1)
            {
                printf("%d ", ptr->data);
                ptr = pop();
            }
            ptr->status = 1;
        }
    }
}

void print_inorder()
{
    if (root == NULL)
    {
        printf("\nThe tree is empty\n");
        return;
    }
    ptr = root;
    push(NULL);
    while (ptr != NULL)
    {
        push(ptr);
        ptr = ptr->left;
        while (ptr == NULL)
        {
            ptr = pop();
            printf("%d ", ptr->data);
            ptr = ptr->right;
        }
    }
}

void print_preorder()
{
    if (root == NULL)
    {
        printf("\nThe tree is empty\n");
        return;
    }
    ptr = root;
    push(NULL);
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        if (ptr->right != NULL)
        {
            push(ptr->right);
        }
        ptr = ptr->left;
        if (ptr == NULL)
        {
            ptr = pop();
        }
    }
}

// Print as tree (horizontally)
void print_tree(struct node *ptr1, int space)
{
    int increase = 10;
    if (ptr1 == NULL)
    {
        return;
    }
    space = space + increase;
    print_tree(ptr1->right, space);
    printf("\n");
    for (int i = increase; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", ptr1->data);
    print_tree(ptr1->left, space);
}

void push(struct node *item)
{
    stk[++top] = item;
}

struct node *pop()
{
    if (isEmpty())
    {
        return NULL;
    }
    else
    {
        return stk[top--];
    }
}

struct node *peek()
{
    if (isEmpty())
    {
        return NULL;
    }
    else
    {
        return stk[top];
    }
}

int isEmpty()
{
    return top == -1 ? 1 : 0;
}
