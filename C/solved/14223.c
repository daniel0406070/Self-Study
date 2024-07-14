#include <stdio.h>

int main(){
    int n;
    int dots[51][2];

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &dots[i][0], &dots[i][1]);
    }

    long long int ans = 0x7fffffffffffffff;
    int a[2];
    int b[2];


    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i == j){
                continue;
            }

            a[0] = -0x7fffffff;
            a[1] = -0x7fffffff;
            b[0] = 0x7fffffff;
            b[1] = 0x7fffffff;



            for(int k = 0; k < n; k++){
                if (k == i || k == j){
                    continue;
                }

                a[0] = dots[k][0]>a[0]?dots[k][0]:a[0];
                a[1] = dots[k][1]>a[1]?dots[k][1]:a[1];
                b[0] = dots[k][0]<b[0]?dots[k][0]:b[0];
                b[1] = dots[k][1]<b[1]?dots[k][1]:b[1];
            }

            int side = a[0]-b[0]>a[1]-b[1]?a[0]-b[0]:a[1]-b[1];
            long long int area = 1LL*(side+2)*(side+2);
            if (area < ans){
                ans = area;
            }
        }
    }

    printf("%lld\n", ans);
}