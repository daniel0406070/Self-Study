#include <stdio.h>
#include <stdlib.h>

char** graph;
char** visited_water;
char** visited;

int queue[5000][3];
int front = 0;
int rear = 0;

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    graph = (char**)malloc((n)*sizeof(char*));
    visited = (char**)malloc((n)*sizeof(char*));
    visited_water = (char**)malloc((n)*sizeof(char*));

    int start_x, start_y;
    for(int i=0; i<n; i++){
        graph[i] = (char*)malloc((m)*sizeof(char));
        visited[i] = (char*)malloc((m)*sizeof(char));
        visited_water[i] = (char*)malloc((m)*sizeof(char));
        for(int j=0; j<m; j++){
            scanf(" %c", &graph[i][j]);
            
            if(graph[i][j] == '*'){
                queue[rear][0] = i;
                queue[rear][1] = j;
                queue[rear++][2] = -1;
                visited_water[i][j] = 1;
                graph[i][j] = '.';
            }
            else if(graph[i][j] == 'S'){
                start_x = i;
                start_y = j;
                graph[i][j] = '.';
            }
        }
    }

    queue[rear][0] = start_x;
    queue[rear][1] = start_y;
    queue[rear++][2] = 0;
    visited[start_x][start_y] = 1;

    while (front < rear)
    {
        int x = queue[front][0];
        int y = queue[front][1];
        int type = queue[front++][2];

        if(type == -1){
            for(int dir=0; dir<4; dir++){
                int nx = x + "2011"[dir] - '1';
                int ny = y + "1120"[dir] - '1';

                if(nx < 0 || ny < 0 || nx >= n || ny >= m || graph[nx][ny] != '.') continue;
                if(visited_water[nx][ny]) continue;
                
                queue[rear][0] = nx;
                queue[rear][1] = ny;
                queue[rear++][2] = -1;
                visited_water[nx][ny] = 1;
            }
        }
        else{
            for(int dir=0; dir<4; dir++){
                int nx = x + "2011"[dir] - '1';
                int ny = y + "1120"[dir] - '1';

                if(nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if(graph[nx][ny] == 'D'){
                    printf("%d\n", type+1);
                    return 0;
                }

                if(graph[nx][ny] != '.' || visited[nx][ny] || visited_water[nx][ny]) continue;

                queue[rear][0] = nx;
                queue[rear][1] = ny;
                queue[rear++][2] = type + 1;
                visited[nx][ny] = 1;
            }
        }
    }

    printf("KAKTUS\n");
    return 0;
}