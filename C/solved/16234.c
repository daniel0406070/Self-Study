#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
typedef struct point{
    int x;
    int y;
}point;

int n,l,r;
int **arr;
int **visited;

point queue[2500];
int front = 0;
int rear = 0;

void push(point p){
    queue[rear++] = p;
}

point pop(){
    return queue[front++];
}

int is_empty(){
    return front == rear;
}


int bfs(point s, int g){
    front = 0;
    rear = 0;

    push(s);
    visited[s.x][s.y] = g;
    int sum = arr[s.x][s.y];

    while(!is_empty()){
        point cur = pop();
        for(int i=0; i<4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny] != 0) continue;
            int diff = abs(arr[cur.x][cur.y] - arr[nx][ny]);
            if(diff >= l && diff <= r){
                point next = {nx, ny};
                push(next);
                visited[nx][ny] = g;
                sum += arr[nx][ny];
            }
        }
    }

    front = 0;

    int cnt = rear;
    if(cnt == 1) return 0;
    else{
        sum /= cnt;

        while(!is_empty()){
            point cur = pop();
            arr[cur.x][cur.y] = sum;
        }
        return 1;
    }
}


int main(){
    scanf("%d %d %d", &n, &l, &r);

    arr = (int **)malloc(sizeof(int *) * n);
    visited = (int **)malloc(sizeof(int *) * n);
    for(int i=0; i<n; i++){
        arr[i] = (int *)malloc(sizeof(int) * n);
        visited[i] = (int *)malloc(sizeof(int) * n);
        memset(visited[i], 0, sizeof(int) * n);
        for(int j=0; j<n; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    int g = 1;
    int flag = 1;
    int day = 0;
    while(flag){
        flag = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(visited[i][j] == 0){
                    flag += bfs((point){i,j}, g++);
                }
            }
        }

        // for(int i=0; i<n; i++){
        //     for(int j=0; j<n; j++){
        //         printf("%d ", arr[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n");


        if(flag){
            for(int i=0; i<n; i++){
                memset(visited[i], 0, sizeof(int) * n);
            }
            day++;
        }
    }

    printf("%d\n", day);

    for(int i=0; i<n; i++){
        free(arr[i]);
        free(visited[i]);
    }


}