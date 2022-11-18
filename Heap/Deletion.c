#include <stdio.h>
//int heap[50] = {-1, 72, 54, 63, 27, 36, 45, 61, 18}, n = 8;
int heap[50] = {-1, 95, 85, 72, 25, 35, 69, 70, 16, 22, 23, 15, 24}, n = 12;
void print_as_tree(int, int);
void print_linearly();
int delete();
int main(void) {
    printf("\nTree before deletion:\n");
    print_as_tree(1, 0);
    int deleted_item = delete();
    printf("\nThe deleted item is %d\n", deleted_item);
    printf("\nAfter deletion:");
    printf("\nMaxheap printed as tree(horizontally):\n");
    print_as_tree(1, 0);
    return 0;
}

//Delete root node of a tree
int delete() {
    int i = 1;
    int par = heap[1], left = heap[2], right = heap[3];
    int root = heap[1], last = heap[n];
    heap[n] = 0;
    while(last < left || last < right) {
        if(left > right) {
            if(left > last) {
                heap[i] = left;
                i = i * 2;
            }
        }
        else {
            if(right > last) {
                heap[i] = right;
                i = i * 2 + 1;
            }
        }
        left = heap[i*2]; right = heap[i*2+1];
    }
    heap[i] = last;
    n = n - 1;
    return root;
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
