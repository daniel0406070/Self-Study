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
int* value;
int* cheap;
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
    if (cheap[idx] == 0 || cheap[idx] > value[v])
        cheap[idx] = value[v];
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
    cheap = (int*)calloc(n + 1, sizeof(int));
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
    int n;
    char t;
    scanf("%d", &n);
    nptr* adj = (nptr*)malloc(n*sizeof(nptr));
    nptr* rev_adj = (nptr*)malloc(n*sizeof(nptr));
    for (int i = 0; i < n; i++){
        adj[i] = NULL;
        rev_adj[i] = NULL;
    }

    value = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++){
        scanf("%d", &value[i]);
    }

    
    for (int i = 0; i < n; i++){
        getchar();
        for (int j = 0; j < n; j++){
            scanf("%c", &t);
            // printf("%c", t);
            if(t == '1'){
                nptr newNode = (nptr)malloc(sizeof(node));
                newNode->vertex = j;
                newNode->next = adj[i];
                adj[i] = newNode;

                newNode = (nptr)malloc(sizeof(node));
                newNode->vertex = i;
                newNode->next = rev_adj[j];
                rev_adj[j] = newNode;

                // printf("%d -> %d\n", i, j);
            }
        }
        // printf("\n");
    }


    topologicalSort(n, adj);
    ssc(n, rev_adj);

    // for (int i = 0; i < n; i++){
    //     printf("%d ", result[i]);
    // }
    // printf("\n");

    // for (int i = 1; i < idx; i++){
    //     printf("%d ", cheap[i]);
    // }
    // printf("\n");

    long long int total = 0;
    for (int i = 1; i < idx; i++){
        total += cheap[i];
    }
    printf("%lld\n", total);

    // Free linked lists
    for (int i = 0; i < n; i++){
        nptr temp = adj[i];
        while(temp != NULL){
            nptr next = temp->next;
            free(temp);
            temp = next;
        }
        temp = rev_adj[i];
        while(temp != NULL){
            nptr next = temp->next;
            free(temp);
            temp = next;
        }
    }

    free(adj);
    free(rev_adj);
    free(stack);
    free(result);
    free(value);
    free(cheap);
}

