#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node{
    int to;
    nptr next;
} node;

nptr* adj;
nptr* adj_rev;
int* weight;
int* topo;
int topo_idx;
int* visited;

void topo_dfs(int u){
    visited[u] = 1;
    nptr temp = adj_rev[u];
    while(temp!=NULL){
        if(visited[temp->to]==0){
            topo_dfs(temp->to);
        }
        temp = temp->next;
    }
    topo[topo_idx++] = u;
}

int main(){
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, m;
        int w;
        scanf("%d %d", &n, &m);

        adj = (nptr*)malloc(sizeof(nptr)*n);
        adj_rev = (nptr*)malloc(sizeof(nptr)*n);
        topo = (int*)malloc(sizeof(int)*n);
        visited = (int*)malloc(sizeof(int)*n);
        weight = (int*)malloc(sizeof(int)*n);
        for(int i=0; i<n; i++){
            adj[i] = NULL;
            adj_rev[i] = NULL;
            scanf("%d", &weight[i]);
            visited[i] = 0;
        }

        for(int i=0; i<m; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            
            u--;
            v--;

            nptr temp = (nptr)malloc(sizeof(node));
            temp->to = v;
            temp->next = adj[u];
            adj[u] = temp;

            temp = (nptr)malloc(sizeof(node));
            temp->to = u;
            temp->next = adj_rev[v];
            adj_rev[v] = temp;
        }

        scanf("%d", &w);
        w--;

        topo_idx = 0;
        for(int i=0; i<n; i++){
            if(visited[i]==0){
                topo_dfs(i);
            }
        }

        for(int i=0; i<n; i++){
            visited[i] = 0;
        }

        for(int i=0; i<n; i++){
            int u = topo[i];
            if(u==w) break;
            nptr temp = adj[u];
            while(temp!=NULL){
                if(visited[temp->to]<visited[u]+weight[u]){
                    visited[temp->to] = visited[u]+weight[u];
                }
                temp = temp->next;
            }
        }

        printf("%d\n", visited[w] + weight[w]);

        for(int i=0; i<n; i++){
            nptr temp;
            while(adj[i]!=NULL){
                temp = adj[i];
                adj[i] = adj[i]->next;
                free(temp);
            }
            while(adj_rev[i]!=NULL){
                temp = adj_rev[i];
                adj_rev[i] = adj_rev[i]->next;
                free(temp);
            }
        }
        free(adj);
        free(adj_rev);
        free(topo);
        free(visited);
        free(weight);
    }    
}