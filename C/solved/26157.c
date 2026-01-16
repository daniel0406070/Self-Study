#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node {
    int vertex;
    nptr next;
} node;

int* stack;
int* visited;
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

void ssc_r(int v, nptr* rev_adj, int* result){
    visited[v] = 1;
    result[v] = idx;
    nptr temp = rev_adj[v];
    while(temp != NULL){
        if(!visited[temp->vertex]){
            ssc_r(temp->vertex, rev_adj, result);
        }
        temp = temp->next;
    }
}

void ssc(int n, nptr* rev_adj, int* result){
    visited = (int*)calloc(n, sizeof(int));
    idx = 0;

    for (int i = 0; i < n; i++){
        int v = stack[i];
        if(!visited[v]){
            ssc_r(v, rev_adj, result);
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
        u--; v--;
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
    int* result = (int*)malloc(n * sizeof(int));
    ssc(n, rev_adj, result);

    // for(int i = 0; i < n; i++){
    //     printf("%d ", result[i]);
    // }
    // printf("\n");

    free(stack);
    nptr* ssc_adj = (nptr*)malloc(idx * sizeof(nptr));
    nptr* ssc_rev_adj = (nptr*)malloc(idx * sizeof(nptr));
    for (int i = 0; i < idx; i++){
        ssc_adj[i] = NULL;
        ssc_rev_adj[i] = NULL;
    }
    for (int i = 0; i < n; i++){
        nptr temp = adj[i];
        while(temp != NULL){
            if (result[i] != result[temp->vertex]){
                nptr newNode = (nptr)malloc(sizeof(node));
                newNode->vertex = result[temp->vertex];
                newNode->next = ssc_adj[result[i]];
                ssc_adj[result[i]] = newNode;

                newNode = (nptr)malloc(sizeof(node));
                newNode->vertex = result[i];
                newNode->next = ssc_rev_adj[result[temp->vertex]];
                ssc_rev_adj[result[temp->vertex]] = newNode;

                // printf("%d -> %d\n", result[i], result[temp->vertex]);
            }
            temp = temp->next;
        }
    }

    topologicalSort(idx, ssc_adj);

    // for(int i = 0; i < idx; i++){
    //     printf("%d ", stack[i]);
    // }
    // printf("\n");

    int* ssc_flag = (int*)calloc(idx, sizeof(int));
    for (int i = 0; i < idx-1; i++){
        nptr temp = ssc_adj[stack[i]];
        while(temp != NULL){
            if (temp->vertex == stack[i+1]){
                ssc_flag[stack[i+1]] = 1;
            }
            temp = temp->next;
        }
    }
    int flag = 0;
    for (int i = 1; i < idx; i++){
        if (ssc_flag[stack[i]] == 0){
            flag = 1;
            break;
        }
    }

    if (flag == 0){
        int cnt = 0;
        for (int i = 0; i < n; i++){
            if (result[i] == stack[0]){
                cnt++;
            }
        }
        printf("%d\n", cnt);
        for (int i = 0; i < n; i++){
            if (result[i] == stack[0]){
                printf("%d ", i + 1);
            }
        }
        printf("\n");
    } else {
        printf("0\n");
    }

}