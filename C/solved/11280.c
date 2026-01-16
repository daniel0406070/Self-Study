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
    nptr* adj = (nptr*)malloc((2*n+1)*sizeof(nptr));
    nptr* rev_adj = (nptr*)malloc((2*n+1)*sizeof(nptr));
    for (int i = 0; i < 2*n+1; i++){
        adj[i] = NULL;
        rev_adj[i] = NULL;
    }

    for (int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        not_u = n - u;
        not_v = n - v;
        u += n;
        v += n;
        nptr newNode = (nptr)malloc(sizeof(node));
        newNode->vertex = v;
        newNode->next = adj[not_u];
        adj[not_u] = newNode;

        newNode = (nptr)malloc(sizeof(node));
        newNode->vertex = u;
        newNode->next = adj[not_v];
        adj[not_v] = newNode;

        newNode = (nptr)malloc(sizeof(node));
        newNode->vertex = not_u;
        newNode->next = rev_adj[v];
        rev_adj[v] = newNode;

        newNode = (nptr)malloc(sizeof(node));
        newNode->vertex = not_v;
        newNode->next = rev_adj[u];
        rev_adj[u] = newNode;

        // printf("%d -> %d and %d -> %d\n", not_u-n, v-n, not_v-n, u-n);
        // printf("%d %d\n", not_u, v);
        // printf("%d %d\n", not_v, u);

        // printf("%d %d\n", v, not_u);
        // printf("%d %d\n", u, not_v);
    }


    topologicalSort(2*n+1, adj);

    // for (int i = 0; i < 2*n+1; i++){
    //     printf("%d ", stack[i]);
    // }
    // printf("\n");

    ssc(2*n+1, rev_adj);

    // for (int i = 0; i < 2*n+1; i++){
    //     printf("%d ", result[i]);
    // }
    // printf("\n");

    int flag = 1;
    for (int i = 0; i < n; i++){
        if(result[i] == result[2*n - i]){
            flag = 0;
            break;
        }
    }

    printf("%d", flag);

//     free(stack);
//     free(visited);
//     free(result);
//     for (int i = 0; i < 2*n+1; i++){
//         nptr temp = adj[i];
//         while(temp != NULL){
//             nptr toFree = temp;
//             temp = temp->next;
//             free(toFree);
//         }
//         temp = rev_adj[i];
//         while(temp != NULL){
//             nptr toFree = temp;
//             temp = temp->next;
//             free(toFree);
//         }
//     }
//     free(adj);
//     free(rev_adj);
//     return 0;
}

