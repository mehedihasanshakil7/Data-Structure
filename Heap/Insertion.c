#include <stdio.h>
int heap[50] = {-1, 72, 54, 63, 27, 36, 45, 61, 18}, n = 8;
void print_as_tree(int, int);
void print_linearly();
void insert(int);
int main(void) {
    int item;
    printf("\nEnter an item: ");
    scanf("%d", &item);
    printf("\nHeap before inserting the item:\n");
    print_linearly();
    printf("Maxheap printed as tree:\n");
    print_as_tree(1, 0);
    insert(item);
    printf("\nHeap after inserting %d is:\n", item);
    print_linearly();
    printf("Maxheap printed as tree:\n");
    print_as_tree(1, 0);
    return 0;
}

//Insert an item in a maxheap
void insert(int item) {
    heap[++n] = item;
    int i = n, temp;
    while(heap[i/2] < item && i > 1) {
        temp = heap[i/2];
        heap[i/2] = item;
        heap[i] = temp;
        i = i / 2;
    }
}

//Print maxheap as a list/array
void print_linearly() {
    for(int i = 1; i <= n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n\n");
}

//Print maxheap as a tree(horizontally)
void print_as_tree(int i, int space) {
    int increase = 10;
    if(heap[i] == 0) {
        return;
    }
    space = space + increase;
    print_as_tree(i*2 + 1, space);
    printf("\n");
    for(int j = increase; j < space; j++) {
        printf(" ");
    }
    printf("%d\n", heap[i]);
    print_as_tree(i*2, space);
}
