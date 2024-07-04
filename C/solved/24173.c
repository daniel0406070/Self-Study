#include <stdio.h>

int n,m;

void swap(void *a, void *b){
    int temp = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = temp;

    if(!(--m))
        if(*(int*)a<*(int*)b)
            printf("%d %d\n", *(int*)a, *(int*)b);
        else
            printf("%d %d\n", *(int*)b, *(int*)a);
}

void heapify(int i, int j, int* heap){
    int left = 2*i;
    int right = 2*i+1;
    int smallest = i;

    if(left<=j && heap[left]<heap[i])
        smallest = left;
    if(right<=j && heap[right]<heap[smallest])
        smallest = right;
    if(smallest!=i){
        swap(&heap[i], &heap[smallest]);
        heapify(smallest, j, heap);
    }
}

void buildHeap(int* heap){
    for(int i=n/2; i>0; i--){
        heapify(i, n, heap);
    }
}

void heapsort(int* heap){
    buildHeap(heap);
    for(int i=n; i>1; i--){
        swap(&heap[1], &heap[i]);
        heapify(1, i-1, heap);
    }
}

int main(){
    scanf("%d %d", &n, &m);

    int heap[500002]={0,};
    for(int i=1; i<=n; i++){
        scanf("%d", &heap[i]);
    }

    heapsort(heap);

    if(m>0)
        printf("-1\n");
}