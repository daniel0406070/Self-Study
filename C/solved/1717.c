#include <stdio.h>

int p[1000004];

int find(int x){
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}

void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    p[x]=y;
}

int main(){
    int n,m;
    int op,a,b;

    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++){
        p[i]=i;
    }

    for(int i=0;i<m;i++){
        scanf("%d %d %d",&op,&a,&b);
        if(op==0) merge(a,b);

        else{
            if(find(a)==find(b)) printf("YES\n");
            else printf("NO\n");
        }
    }
}