#include <stdio.h> 

int ck[1000000]={0,};
int map[5][5];

void dfs(int x,int y,int cnt,int num){
    if(cnt==6){
        ck[num]=1;
        return;
    }
    if(x<0||x>=5||y<0||y>=5) return;
    
    dfs(x+1,y,cnt+1,num*10+map[x][y]);
    dfs(x-1,y,cnt+1,num*10+map[x][y]);
    dfs(x,y+1,cnt+1,num*10+map[x][y]);
    dfs(x,y-1,cnt+1,num*10+map[x][y]);
}

int main(){
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&map[i][j]);
        }
    }

    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            dfs(i,j,0,0);
        }
    }

    int cnt=0;
    for(int i=0;i<1000000;i++){
        if(ck[i]) cnt++;
    }
    printf("%d",cnt);
}