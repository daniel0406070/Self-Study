#include <stdio.h>
#define MAX 100005

int p[MAX];
long long int dist[MAX];

int find(int node){
    if (p[node] == node) return node;
    
    int parent = find(p[node]);
    dist[node] += dist[p[node]];
    return p[node] = parent;
}

void unionpw(int a, int b, int c){
    int pa = find(a);
    int pb = find(b);
    if (pa==pb) return;

    dist[pb] = dist[a] - dist[b] + c;
    p[pb] = pa;
    return;
    
}

int main(){
    int n=1,m=1;
    char op[1];
    int a,b,c;
    while (1)
    {
        scanf("%d %d",&n,&m);
        if (n==0 && m==0) break;
        for (int i = 0; i <= n; i++)
        {
            p[i]=i;
            dist[i]=0;
        }
        
        for (int i = 0; i < m; i++)
        {
            scanf("%s",op);
            scanf("%d %d",&a,&b);
            if (op[0]==63){
                if (find(a)==find(b)) printf("%lld\n",dist[b]-dist[a]);
                else printf("UNKNOWN\n");
            }
            else{
                scanf("%d",&c);
                unionpw(a,b,c);
            }
        }
    }
}