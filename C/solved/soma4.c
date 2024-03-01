/*
소마 15기 4번 문제 기억으로는 이럼

배열 하나를 주고 배치하는건데
요소의 값%len = 그 요소의 index 인 경우를 카운트하고
그 카운트가 가장 많은거 중에
가장 사전순으로 빠른거
*/


#include <stdio.h>
#include <stdlib.h>

int n;
int max = 0;

int used[100]={0,};
int oarr[100]={0,};
int arr[100]={0,};
int tmp[100]={0,};

int cmp(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

void bt(int k){
    int cnt = 0;
    for(int i=0; i<k; i++){
        if(arr[i]%n == i) cnt++;
    }

    if(k == n){
        if(cnt > max){
            max = cnt;

            for(int i=0; i<n; i++){
                tmp[i] = arr[i];
            }
        }

        return;
    }
    if(n-k+cnt < max) return;

    for(int i=0; i<n; i++){
        if(used[i] == 1) continue;

        used[i] = 1;
        arr[k] = oarr[i];
        bt(k+1);
        used[i] = 0;
    }
}

int main(){
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &oarr[i]);
    }
    qsort(oarr, n, sizeof(int), cmp);

    int cnt = 0;

    bt(0);
    


    for(int i=0; i<n; i++){
        printf("%d ", tmp[i]);
    }

}