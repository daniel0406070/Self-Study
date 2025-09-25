#include <stdio.h>
#define MAX 52

int p[MAX];

int find(int x){
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}

void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if (x==0) p[y]=x;
    else p[x]=y;
}

int main(){
    int n,m;
    int pnum,pname;
    int a,b;
    
    int party[MAX];

    scanf("%d %d",&n,&m);
    for(int i=0;i<=n;i++){
        p[i]=i;
    }
    scanf("%d",&pnum);
    for(int i=0;i<pnum;i++){
        scanf("%d",&pname);
        p[pname]=0;
    }

    for(int i=0;i<m;i++){
        a=-1,b=-1;
        scanf("%d",&pnum);
        for (int j=0;j<pnum;j++){
            scanf("%d",&b);
            if (a!=-1) merge(a,b);
            a=b;
        }
        party[i]=b;
    }

    int ans=0;

    for(int i=0;i<m;i++){
        if(find(party[i])!=0) ans++;
    }

    printf("%d",ans);
}