#include <stdio.h>
int main(void) {
    int n = 8, item;
    int heap[50] = {-1, 72, 54, 63, 27, 36, 45, 61, 18};
    printf("\nEnter an item: ");
    scanf("%d", &item);
    printf("\nHeap before inserting the item:\n");
    for(int i = 1; i <= n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
    heap[++n] = item;
    int i = n , temp;
    while(heap[i/2] < item && i > 1) {
        temp = heap[i/2];
        heap[i/2] = item;
        heap[i] = temp;
        i = i / 2;
    }
    printf("\nHeap after inserting %d is:\n", item);
    for(i = 1; i <= n; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n\n");
    return 0;
}
