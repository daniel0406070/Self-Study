#include <stdio.h>

int main(){
    int n, p[50][2], r[50];
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d %d", &p[i][0], &p[i][1]);
        r[i] = 1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(p[i][0] < p[j][0] && p[i][1] < p[j][1]){
                r[i]++;
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", r[i]);
    }
}

// 둘다 높은 사람이 있으면 랭크를 올려준다.
// n이 50이므로 O(n^2)으로 풀어도 된다.