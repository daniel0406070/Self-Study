#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct pos{
    int x;
    int y;
} pos;




int n;
int map[20][20];
int visited[20][20]={0,};
int dir[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

pos queue[450]; 
int front=0;
int rear=0;

void push(pos p){
    queue[rear++]=p;
}

pos pop(){
    return queue[front++];
}

int empty(){
    return front==rear;
}

int cmp(const void *a,const void *b){
    if(visited[((pos*)a)->x][((pos*)a)->y]==visited[((pos*)b)->x][((pos*)b)->y]){
        if(((pos*)a)->x==((pos*)b)->x) return ((pos*)a)->y-((pos*)b)->y;
        return ((pos*)a)->x-((pos*)b)->x;
    }
    return visited[((pos*)a)->x][((pos*)a)->y]-visited[((pos*)b)->x][((pos*)b)->y];
}

int bfs(pos baby_pos){
    int baby_size=2;
    int baby_exp=0;
    int baby_time=0;

    push(baby_pos);
    visited[baby_pos.x][baby_pos.y]=1;
    int time;

    while(!empty()){
        pos cur=pop();
        time=visited[cur.x][cur.y];

        // printf("%d %d\n",cur.x,cur.y);
        for(int i=0;i<4;i++){
            pos next;
            next.x=cur.x+dir[i][0];
            next.y=cur.y+dir[i][1];

            if(next.x<0||next.x>=n||next.y<0||next.y>=n) continue;
            if(visited[next.x][next.y]) continue;
            if(map[next.x][next.y]>baby_size) continue;
            
            

            if(map[next.x][next.y]!=0&&map[next.x][next.y]<baby_size){
                pos *fish=malloc(sizeof(pos)*400);
                int fish_cnt=0;
                fish[fish_cnt++]=next;

                visited[next.x][next.y]=time+1;
                while(!empty()){
                    pos cur=pop();
                    int tmp_time=visited[cur.x][cur.y];

                    for(int i=0;i<4;i++){
                        pos next;
                        next.x=cur.x+dir[i][0];
                        next.y=cur.y+dir[i][1];

                        if(next.x<0||next.x>=n||next.y<0||next.y>=n) continue;
                        if(visited[next.x][next.y]) continue;
                        if(map[next.x][next.y]>baby_size) continue;
                        
                        if(map[next.x][next.y]!=0&&map[next.x][next.y]<baby_size){
                            fish[fish_cnt++]=next;
                        }
                        visited[next.x][next.y]=tmp_time+1;
                    }
                }
                qsort(fish,fish_cnt,sizeof(pos),cmp);
                // for(int i=0;i<fish_cnt;i++){
                //     printf("%d %d\n",fish[i].x,fish[i].y);
                // }
                // printf("\n");

                next=fish[0];
                free(fish);

                baby_exp++;
                if(baby_exp==baby_size){
                    baby_size++;
                    baby_exp=0;
                }
                
                // visited[next.x][next.y]=time+100;
                // for(int i=0;i<n;i++){
                //     for(int j=0;j<n;j++){
                //         printf("%3d ",visited[i][j]);
                //     }
                //     printf("\n");
                // }
                // printf("\n");

                memset(visited,0,sizeof(visited));
                front=0;
                rear=0;
                
                visited[next.x][next.y]=time+1;
                map[next.x][next.y]=0;

                baby_pos=next;
                baby_time=time;

                push(next);
                break;
            }
            
            visited[next.x][next.y]=time+1;
            push(next);
        }
        
    }
    return baby_time;
}

int main(){
    scanf("%d",&n);

    pos baby_pos;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&map[i][j]);
            if(map[i][j]==9) {
                baby_pos.x=i;
                baby_pos.y=j;
                map[i][j]=0;
            }
        }
    }

    printf("%d\n",bfs(baby_pos));
}