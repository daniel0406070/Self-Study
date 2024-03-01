#include <stdio.h>

int n;
int map[100][100];
int visited[100][100]={0,};
int cnt = 1;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

void dfs(int x, int y){
    visited[x][y] = cnt;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(visited[nx][ny] != 0) continue;
        if(map[nx][ny] != map[x][y]) continue;

        dfs(nx, ny);
    }
}

void gr_dfs(int x, int y){
    visited[x][y] = cnt;

    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(visited[nx][ny] != 0) continue;
        if(map[x][y] == 3 && map[nx][ny] != 3) continue;
        if(map[x][y] != 3 && map[nx][ny] == 3) continue;

        gr_dfs(nx, ny);
    }
}

int main(){
    scanf("%d", &n);

    char c;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf(" %c", &c);
            if(c == 'R') map[i][j] = 1;
            else if(c == 'G') map[i][j] = 2;
            else map[i][j] = 3; //B
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == 0){
                dfs(i, j);
                cnt++;
            }
        }
    }
    printf("%d ", cnt-1);

    cnt = 1;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            visited[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(visited[i][j] == 0){
                gr_dfs(i, j);
                cnt++;
            }
        }
    }
    printf("%d", cnt-1);

}