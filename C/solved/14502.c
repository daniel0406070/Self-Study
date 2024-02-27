#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct point{
    int x;
    int y;
}point;

point queue[100];
point two[100];
int two_cnt = 0;
int one_cnt = 0;

int front = 0;
int rear = 0;

void push(point data){
    queue[rear++] = data;
}

point pop(){
    return queue[front++];
}

int n,m;
int map[8][8]={0,};
int visited[8][8]={0,};

int bfs(){
    front = 0;
    rear = 0;
    memset(visited, 0, sizeof(visited));

    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};
    int nx, ny;
    int cnt = 0;

    
    for(int i=0; i<two_cnt; i++){
        push(two[i]);
        visited[two[i].x][two[i].y] = 1;
    }

    while(front<rear){
        point tmp = pop();

        for(int i=0; i<4; i++){
            nx = tmp.x + dx[i];
            ny = tmp.y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(map[nx][ny] == 1) continue;
            if(visited[nx][ny] == 1) continue;

            visited[nx][ny] = 1;
            push((point){nx,ny});
        }

        cnt++;
    }
    
    return cnt;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 2) two[two_cnt++] = (point){i,j};
            else if(map[i][j] == 1) one_cnt++;
        }
    }

    int min = 100;
    int tmp = 0;

    for(int i=0; i<n*m; i++){
        if(map[i/m][i%m] != 0) continue;
        map[i/m][i%m] = 1;

        for(int j=i+1; j<n*m; j++){
            if(map[j/m][j%m] != 0) continue;
            map[j/m][j%m] = 1;

            for(int k=j+1; k<n*m; k++){
                if(map[k/m][k%m] != 0) continue;
                map[k/m][k%m] = 1;
                
                tmp = bfs();
                if(tmp < min) min = tmp;


                map[k/m][k%m] = 0;
            }
            map[j/m][j%m] = 0;
        }
        map[i/m][i%m] = 0;
    }
    

    printf("%d", n*m-min-one_cnt-3);
}