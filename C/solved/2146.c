#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 32003

typedef struct point{
    int x;
    int y;
}point;

int n;
int map[101][101]={0,};
int visit[101][101]={0,};
int len[101][101]={0,};
int id[101][101]={0,};
int id_num=1;

point queue[MAX];
int front=0,rear=0;

void enqueue(point x){
    queue[rear++]=x;
    if(MAX-1==rear) rear=0;
}

point dequeue(){
    point a = queue[front++];
    if(MAX-1==front) front=0;

    return a;
}

int find_border(int x, int y){
    if (x<0 || y<0 || x>=n || y>=n) return 0;
    if (map[x][y]==-1) return 0;
    if (map[x][y]==0){
        return 1;
    } 
    if (map[x][y]==1){
        map[x][y]=-1;
    }
    int f=0;
    
    if(find_border(x-1,y)) f|=1;
    if(find_border(x+1,y)) f|=1;
    if(find_border(x,y-1)) f|=1;
    if(find_border(x,y+1)) f|=1;

    if (f==1){
        enqueue((point){x,y});
        id[x][y]=id_num;
        return 0;
    }
    else return 0;
}

void print_len(int k[][101]){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf("%2d ", k[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


void explore(int x, int y){
    if (x<0 || y<0 || x>=n || y>=n) return;
    if (visit[x][y]==1) return;
    if (map[x][y]==1){
        find_border(x,y);
        id_num++;
    }
    visit[x][y]=1;
    explore(x-1,y);
    explore(x+1,y);
    explore(x,y-1);
    explore(x,y+1);
}

void draw_border(){
    int tmp_front=front;
    int tmp_rear=rear;
    while(front!=rear){
        point a = dequeue();
        map[a.x][a.y]=1;
        len[a.x][a.y]=0;
    }
    front=tmp_front;
    rear=tmp_rear;
}


int search(){
    
    enqueue((point){-6,-6});

    int min=0x7fffffff;
    while(front!=rear){
        point a = dequeue();
        int x=a.x;
        int y=a.y;

        if (x==-6 && y==-6){
            if (min!=0x7fffffff) return min;
            else enqueue((point){-6,-6});
        }

        if (x<0 || y<0 || x>=n || y>=n) continue;


        if (x>=0 && y+1>=0 && x<n && y+1<n){
            if (id[x][y+1] && id[x][y+1]!=id[x][y]){
                if (len[x][y+1]!=0){
                    if (len[x][y+1]==len[x][y]) min=min>len[x][y+1]*2?len[x][y+1]*2:min;
                    else min=min>(len[x][y+1]-1)*2+1?(len[x][y+1]-1)*2+1:min;
                }
            }
            else if (map[x][y+1]==0){
                map[x][y+1]=1;
                len[x][y+1]=len[x][y]+1;
                id[x][y+1]=id[x][y];
                enqueue((point){x,y+1});
            }
            
        }

        if (x>=0 && y-1>=0 && x<n && y-1<n){
            if (id[x][y-1] && id[x][y-1]!=id[x][y]){
                if (len[x][y-1]!=0){
                    if (len[x][y-1]==len[x][y]) min=min>len[x][y-1]*2?len[x][y-1]*2:min;
                    else min=min>(len[x][y-1]-1)*2+1?(len[x][y-1]-1)*2+1:min;
                }
            }
            else if (map[x][y-1]==0){
                map[x][y-1]=1;
                len[x][y-1]=len[x][y]+1;
                id[x][y-1]=id[x][y];
                enqueue((point){x,y-1});
            }
            
        }

        if (x+1>=0 && y>=0 && x+1<n && y<n){
            if (id[x+1][y] && id[x+1][y]!=id[x][y]){
                if (len[x+1][y]!=0){
                    if (len[x+1][y]==len[x][y]) min=min>len[x+1][y]*2?len[x+1][y]*2:min;
                    else min=min>(len[x+1][y]-1)*2+1?(len[x+1][y]-1)*2+1:min;
                }
            }
            else if (map[x+1][y]==0){
                map[x+1][y]=1;
                len[x+1][y]=len[x][y]+1;
                id[x+1][y]=id[x][y];
                enqueue((point){x+1,y});
            }
            
        }

        if (x-1>=0 && y>=0 && x-1<n && y<n){
            if (id[x-1][y] && id[x-1][y]!=id[x][y]){
                if (len[x-1][y]!=0){
                    if (len[x-1][y]==len[x][y]) min=min>len[x-1][y]*2?len[x-1][y]*2:min;
                    else min=min>(len[x-1][y]-1)*2+1?(len[x-1][y]-1)*2+1:min;
                }
            }
            else if (map[x-1][y]==0){
                map[x-1][y]=1;
                len[x-1][y]=len[x][y]+1;
                id[x-1][y]=id[x][y];
                enqueue((point){x-1,y});
            }
            
        }


    }
    return min;
}

int main(){
    
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &map[i][j]);
        }
    }

    explore(0,0);
    draw_border();

    printf("%d\n", search());

    



}