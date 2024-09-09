#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100002

typedef struct link *lptr;
typedef struct link{
    int data;
    lptr next;
} link;

lptr head[MAX];
int depth[MAX];
int dp[MAX][18];

void set_tree(int n, int d){
    for (lptr cur = head[n]; cur; cur = cur->next){
        if(dp[cur->data][0] == 0){
            dp[cur->data][0] = n;
            depth[cur->data] = d;
            set_tree(cur->data, d+1);
        }
    }
}

int LCA(int a, int b){
    if (depth[a] < depth[b]){
        int tmp = a;
        a = b;
        b = tmp;
    }

    for (int i = 17; i >= 0; i--){
        if (pow(2, i) <= depth[a] - depth[b]){
            a = dp[a][i];
        }
    }

    if (a == b) return a;

    for (int i = 17; i >= 0; i--){
        if (dp[a][i] == dp[b][i]) continue;
        a = dp[a][i];
        b = dp[b][i];
    }

    return dp[a][0];
}

int main(){
    int n,m;
    scanf("%d", &n);
    
    int x,y;
    for (int i = 0; i < n-1; i++){
        scanf("%d %d", &x, &y);
        lptr tmp = (lptr)malloc(sizeof(struct link));
        tmp->data = y;
        tmp->next = head[x];
        head[x] = tmp;

        tmp = (lptr)malloc(sizeof(struct link));
        tmp->data = x;
        tmp->next = head[y];
        head[y] = tmp;
    }

    dp[1][0] = -1;
    set_tree(1, 1);

    dp[1][0] = -1;
    
    for (int i = 1; i < 18; i++){
        for (int j = 1; j <= n; j++){
            if (dp[j][i-1] != -1){
                dp[j][i] = dp[dp[j][i-1]][i-1];
            }
        }
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        printf("%d\n", LCA(x, y));
    }
}