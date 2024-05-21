#include <stdio.h>
#include <stdlib.h>
#define inf 0x7fffffff
typedef struct node* nptr;
typedef struct node{
    int u;
    int w;
    nptr next;
}node;

nptr* graph;

int main(){

    int E,V;
    scanf("%d %d", &V, &E);

    graph = (nptr*)malloc(sizeof(nptr)*V);
    for(int i=0; i<V; i++){
        graph[i] = NULL;
    }

    for(int i=0; i<E; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--;
        v--;
        nptr temp = (nptr)malloc(sizeof(node));
        temp->u = v;
        temp->w = w;
        temp->next = graph[u];
        graph[u] = temp;

        temp = (nptr)malloc(sizeof(node));
        temp->u = u;
        temp->w = w;
        temp->next = graph[v];
        graph[v] = temp;
    }
    
    int* dist = (int*)malloc(sizeof(int)*V);
    int* visited = (int*)malloc(sizeof(int)*V);

    for(int i=1; i<V; i++){
        dist[i] = inf;
        visited[i] = 0;
    }
    visited[0] = 0;

    int idx = 0;
    while(1){
        int min = inf;
        nptr temp = graph[idx];
        while(temp!=NULL){
            if(dist[temp->u]>temp->w&&visited[temp->u]==0){
                dist[temp->u] = temp->w;
            }
            temp = temp->next;
        }
        
        visited[idx] = 1;
        for(int i=0; i<V; i++){
            if(visited[i]==0 && min>dist[i]){
                min = dist[i];
                idx = i;
            }
        }
        
        
        if(min==inf) break;
    }

    long long int sum = 0;
    for(int i=0; i<V; i++){
        if(dist[i]!=inf)
            sum+=dist[i];
    }

    printf("%lld\n", sum);
}
