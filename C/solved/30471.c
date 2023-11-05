#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int slimes[200004][3]={0,};

int find(int a){
    if(slimes[a][0]==a){
        return a;
    }
    else{
        return slimes[a][0]=find(slimes[a][0]);
    }
}

int merge(int a, int b){
    int pa=find(a);
    int pb=find(b);

    if(pa==pb){
        return 0;
    }
    else{
        slimes[pa][1]+=slimes[pb][1];
        slimes[pb][0]=pa;
        return 1;
    }
}

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i=1; i<=n; i++){
        slimes[i][0]=i;
        slimes[i][1]=1;
    }

    int a,b;
    long long int ans=0;
    for(int i=0; i<m; i++){
        scanf("%d %d", &a, &b);
        int pa=find(a);
        int pb=find(b);

        if(pa==pb){
            printf("%lld\n", ans+n);
            continue;
        }
        ans-=1LL*slimes[pa][1]*(slimes[pa][1]-1)/2;
        ans-=1LL*slimes[pb][1]*(slimes[pb][1]-1)/2;


        merge(a,b);

        pa=find(a);
        ans+=1LL*slimes[pa][1]*(slimes[pa][1]-1)/2;
        
        printf("%lld\n", ans+n);
    }
} 
//2 1
//3 3
//4 6
//5 10