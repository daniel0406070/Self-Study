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
    int t;
    scanf("%d", &t);
    while(t--){
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

        ssc(n, rev_adj);


        int* connected = (int*)calloc(n+1, sizeof(int));
    
        for (int i = 0; i < n; i++){
            nptr temp = adj[i];
            while(temp != NULL){
                if(result[i] != result[temp->vertex]){
                    connected[result[temp->vertex]] = 1;
                }
                temp = temp->next;
            }
        }

        // for (int i = 0; i < n; i++){
        //     printf("%d ", result[i]);
        // }
        // printf("\n");

        // for (int i = 1; i < idx; i++){
        //     printf("%d ", connected[i]);
        // }
        // printf("\n");
        
        int count = 0;
        int ans = -1;
        for (int i = 1; i < idx; i++){
            if(connected[i] == 0){
                count++;
                ans = i;
            }
        }
        
        int flag = count == 1 ? 1 : 0;

        if(flag){
            for(int i=0; i<n; i++){
                if(result[i] == ans){
                    printf("%d\n", i);
                }
            }
        }
        else{
            printf("Confused\n");
        }


        for (int i = 0; i < n; i++){
            nptr temp;
            while(adj[i] != NULL){
                temp = adj[i];
                adj[i] = adj[i]->next;
                free(temp);
            }
            while(rev_adj[i] != NULL){
                temp = rev_adj[i];
                rev_adj[i] = rev_adj[i]->next;
                free(temp);
            }
        }

        free(adj);
        free(rev_adj);
        free(stack);
        free(result);
        free(connected);
        printf("\n");
    }
}