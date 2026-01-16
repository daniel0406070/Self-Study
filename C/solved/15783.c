#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node {
    int vertex;
    nptr next;
} node;

int* stack;
int* visited;
int* result;
int top;
int idx;

void topologicalSortRecur(int v, nptr* adj){
    visited[v] = 1;
    nptr temp = adj[v];
    while(temp != NULL){
        if(!visited[temp->vertex]){
            topologicalSortRecur(temp->vertex, adj);
        }
        temp = temp->next;
    }
    stack[--top] = v;
}

void topologicalSort(int n, nptr* adj){
    stack = (int*)calloc(n, sizeof(int));
    visited = (int*)calloc(n, sizeof(int));
    top = n;

    for (int i = 0; i < n; i++){
        if(!visited[i]){
            topologicalSortRecur(i, adj);
        }
    }

    free(visited);
}

void ssc_r(int v, nptr* rev_adj){
    visited[v] = 1;
    result[v] = idx;
    nptr temp = rev_adj[v];
    while(temp != NULL){
        if(!visited[temp->vertex]){
            ssc_r(temp->vertex, rev_adj);
        }
        temp = temp->next;
    }
}

void ssc(int n, nptr* rev_adj){
    visited = (int*)calloc(n, sizeof(int));
    result = (int*)calloc(n, sizeof(int));
    idx = 1;

    for (int i = 0; i < n; i++){
        int v = stack[i];
        if(!visited[v]){
            ssc_r(v, rev_adj);
            idx++;  
        }
    }

    free(visited);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int u, v;
    int not_u, not_v;
    nptr* adj = (nptr*)malloc(n*sizeof(nptr));
    nptr* rev_adj = (nptr*)malloc(n*sizeof(nptr));
    for (int i = 0; i < n; i++){
        adj[i] = NULL;
        rev_adj[i] = NULL;
    }

    for (int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        nptr newNode = (nptr)malloc(sizeof(node));
        newNode->vertex = v;
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = (nptr)malloc(sizeof(node));
        newNode->vertex = u;
        newNode->next = rev_adj[v];
        rev_adj[v] = newNode;
    }


    topologicalSort(n, adj);
    ssc(n, adj);

    // for (int i = 0; i < n; i++){
    //     printf("%d ", result[i]);
    // }
    // printf("\n");
    
    printf("%d\n", idx - 1);

}