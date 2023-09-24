#define MAX 1000004

int p[MAX];

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