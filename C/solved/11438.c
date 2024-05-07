#include <stdio.h>
#include <stdlib.h>

#define ML 18
#define MAX (1<<ML)

typedef struct node *nptr;
typedef struct node{
    int data;
    nptr next;
} node;
nptr head[MAX];

int n,m;

int parent[MAX][ML]={0,};
int depth[MAX]={0,};


void insert_edge(int x, int y){
    nptr tmp = (nptr)malloc(sizeof(struct node));
    tmp->data = y;
    tmp->next = head[x];
    head[x] = tmp;

    tmp = (nptr)malloc(sizeof(struct node));
    tmp->data = x;
    tmp->next = head[y];
    head[y] = tmp;
}

void dp(int cur, int dep){
    depth[cur] = dep;
    for (nptr i = head[cur]; i != NULL; i = i->next){
        if(i->data == parent[cur][0]) continue;
        if (depth[i->data] == 0){
            parent[i->data][0] = cur;
            dp(i->data, dep+1);
        }
    }
}

void make_parent(){
    dp(1, 0);
    for (int i = 1; i < ML; i++){
        for (int j = 1; j <= n; j++){
            parent[j][i] = parent[parent[j][i-1]][i-1];
        }
    }
}

int lca(int x, int y){
    if (depth[x] > depth[y]){
        int tmp = x;
        x = y;
        y = tmp;
    }

    for (int i = ML-1; i >= 0; i--){
        if (depth[y] - depth[x] >= (1<<i)){
            y = parent[y][i];
        }
    }

    if (x == y) return x;
    for (int i = ML-1; i >= 0; i--){
        if (parent[x][i] != parent[y][i]){
            x = parent[x][i];
            y = parent[y][i];
        }
    }


    return parent[x][0];
}

int main(){
    scanf("%d", &n);
    
    int x,y;
    for (int i = 0; i < n-1; i++){
        scanf("%d %d", &x, &y);
        insert_edge(x,y);
    }

    make_parent();
    
    scanf("%d", &m); 
    for (int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        printf("%d\n", lca(x,y));
    }
}