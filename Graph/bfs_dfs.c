#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    int status;
    struct node *next;
    struct adj *adj;
};
struct adj {
    struct node *node;
    struct adj *adj;
};
struct node *start = NULL, *ptr = NULL;
struct adj *adjptr = NULL;
int n;
void create_graph();
void create_node_list();
struct node* create_node(int);
struct adj* create_adj(struct node*);
void display();
void bfs();
void reset();
void dfs();
int main() {
    create_graph();
    display();
    printf("\n");
    bfs();
    puts("\n");
    reset();
    dfs();
    puts("\n");
    return 0;
}

//Create the graph
void create_graph() {
    int item;
    printf("\n\nEnter number of vertices in the graph: ");
    scanf("%d", &n);
    create_node_list();
    ptr = start; //ptr goes from node 0 to n-1
    for(int i = 0; i < n; i++) {
        printf("\nEnter neighbors of %d (-1 to stop): ", i);
        while(1) { //Building the adjacency list
            struct node *temp;
            temp = start;
            scanf("%d", &item);
            if(item == -1) break;
            while(1) { //This loop is for searching
                if(temp == NULL) {
                    printf("\n%d is not a node. So, it's filtered out", item);
                    break;
                }
                if(temp->data == item) {
                    if(ptr->adj == NULL) {
                        ptr->adj = create_adj(temp);
                        adjptr = ptr->adj;
                    }
                    else {
                        adjptr->adj = create_adj(temp);
                        adjptr = adjptr->adj;
                    }
                    break;
                }
                temp = temp->next;
            }
        }
        ptr = ptr->next;
    }
}

//Create node list from 0 to n-1
void create_node_list() {
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            start = create_node(i);
            ptr = start;
        }
        else {
            ptr->next = create_node(i);
            ptr = ptr->next;
        }
    }
}

//Create adjacency list
struct adj* create_adj(struct node *temp) {
    struct adj *temp_adj = (struct adj*)malloc(sizeof(struct adj));
    temp_adj->node = temp;
    temp_adj->adj = NULL;
    return temp_adj;
}

//Create node and return pointer
struct node* create_node(int info) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = info;
    temp->status = 0;
    temp->next = NULL;
    temp->adj = NULL;
    return temp;
}

//Display the graph as adjacency list
void display() {
    printf("\nThe adjacency list is:\n");
    ptr = start;
    for(int i = 0; i < n; i++) {
        printf("%d--> ", i);
        adjptr = ptr->adj;
        while(adjptr != NULL) {
            printf("%d ", adjptr->node->data);
            adjptr = adjptr->adj;
        }
        printf("\n");
        ptr = ptr->next;
    }
    printf("\n");
}

//Traverse the whole graph using bfs
void bfs() {
    printf("\nResult of bfs: ");
    struct node *que[100];
    int front = -1, rear = -1;
    que[++rear] = start; front++; start->status = 1;
    while (front <= rear)
    {
        ptr = que[front++];
        printf("%d ", ptr->data); ptr->status = 2;
        adjptr = ptr->adj;
        while (adjptr != NULL)
        {
            if(adjptr->node->status == 0) {
                que[++rear] = adjptr->node;
                adjptr->node->status = 1;
            }
            adjptr = adjptr->adj;
        }
    }
}

//Traverse the whole graph using dfs
void dfs() {
    printf("\nResult of dfs: ");
    int top = -1;
    struct node *stk[100];
    stk[++top] = start; start->status = 1;
    while(top != -1) {
        ptr = stk[top--];
        printf("%d ", ptr->data);
        ptr->status = 2;
        adjptr = ptr->adj;
        while(adjptr != NULL) {
            if(adjptr->node->status == 0) {
                stk[++top] = adjptr->node;
                adjptr->node->status = 1;
            }
            adjptr = adjptr->adj;
        }
    }
}

//Status field reset to 0
void reset() {
    ptr = start;
    while (ptr != NULL)
    {
        ptr->status = 0;
        ptr = ptr->next;
    }
}
