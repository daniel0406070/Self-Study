#include <stdio.h>

int mission[102][3]={0,};

int main(){
    int n;
    int m,k,d,a;
    long long int tmp_p, total_p=0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        total_p = 0;
        scanf("%d", &m);
        for(int j = 0; j < m; j++){
            scanf("%d %d %d", &k, &d, &a);
            mission[j][0] = k;
            mission[j][1] = d;
            mission[j][2] = a;
        }

        scanf("%d %d %d", &k, &d, &a);

        for(int j = 0; j < m; j++){
            tmp_p = 0;
            tmp_p += 1L*mission[j][0]*k;
            tmp_p -= 1L*mission[j][1]*d;
            tmp_p += 1L*mission[j][2]*a;

            if(tmp_p > 0){
                total_p += tmp_p;
            }
        }

        printf("%lld\n", total_p);
    }
}