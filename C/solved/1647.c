#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct edge{
    int u, v, w;
}edge;

typedef struct graph{
    int V, E;
    edge* edges;
    int *parent;
}graph;

graph* a;

int cmp_edge(const void* a, const void* b){
    return ((edge*)a)->w - ((edge*)b)->w;
}

int find(int i){
    if(a->parent[i]==i) return i;
    a->parent[i]=find(a->parent[i]);
    return a->parent[i];
    }

void union_edge(int x, int y){
    int xset = find(x);
    int yset = find(y);
    a->parent[xset] = yset;
}

int main(){
    a=(graph*)malloc(sizeof(graph));


    scanf("%d %d", &a->V, &a->E);
    
    a->parent = (int*)malloc(a->V*sizeof(int));
    a->edges = (edge*)malloc(a->E*sizeof(edge));
    for(int i=0; i<a->V; i++) a->parent[i]=i;
    for(int i=0; i<a->E; i++){
        scanf("%d %d %d", &a->edges[i].u, &a->edges[i].v, &a->edges[i].w);
        a->edges[i].u--;
        a->edges[i].v--;
    }
    qsort(a->edges, a->E, sizeof(edge), cmp_edge);

    long long int sum = 0;
    long long int max = 0;
    for(int i=0; i<a->E; i++){
        int x = find(a->edges[i].u);
        int y = find(a->edges[i].v);
        if(x!=y){
            union_edge(x, y);
            sum+=a->edges[i].w;
            if(max<a->edges[i].w) max = a->edges[i].w;
        }
    }

    printf("%lld\n", sum-max);
}