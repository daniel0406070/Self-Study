#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5000012

int heap[MAX]={0,};
int num[MAX]={0,};

void sw(int a, int b){
    int tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;
}

void heapify(int i, int n){
    int l = 2*i;
    int r = 2*i+1;
    int min = i;
    if(l <= n && num[heap[l]] < num[heap[min]]) min = l;
    if(r <= n && num[heap[r]] < num[heap[min]]) min = r;
    if(min != i){
        sw(i, min);

        heapify(min, n);
    }
}

void push(int x, int n){
    heap[++n] = n;
    num[n] = x;

    for(int i=n; i>1; i/=2){
        if(num[heap[i]] < num[heap[i/2]]){
            sw(i, i/2);
        }
        else break;
    }
}

void swap(int a, int b, int n){
    num[b] = a;
    heapify(b, n);

    for(int i=b; i>1; i/=2){
        if(num[heap[i]] < num[heap[i/2]]){
            sw(i, i/2);
        }
        else break;
    }
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int a;
    for(int i=1; i<=n; i++){
        scanf("%d", &a);
        if(i<=m) push(a, i-1);
        else{
            swap(a, (i-1)%m+1, m);
        }
        printf("%d ", heap[1]);
    }
}