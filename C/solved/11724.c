#include <stdio.h>  
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Node* nptr;
typedef struct Node{
    int data;
    nptr next;
}Node;

nptr point[1001];

void push(int n, int m){
    nptr newNode = (nptr)malloc(sizeof(Node));
    newNode->data = m;
    if(point[n] == NULL) newNode->next = NULL;
    else newNode->next = point[n];
    point[n] = newNode;
}

int visited[1001]={0,};

int dfs(int n){
    if(visited[n] == 1){
        return 0;
    }
    visited[n] = 1;
    nptr cur = point[n];
    while(cur != NULL){
        dfs(cur->data);
        cur = cur->next;
    }
    return 1;
}

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        push(a, b);
        push(b, a);
    }

    int count = 0;
    for(int i = 1; i <= n; i++){
        if(dfs(i) == 1){
            count++;
        }
    }
    printf("%d", count);
}