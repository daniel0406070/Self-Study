#include <stdio.h>

int main(){
    int n[3];
    scanf("%d %d %d", &n[0], &n[1], &n[2]);

    if(n[0]+n[1]+n[2] >= 100) printf("OK");
    else{
        int min = n[0];
        for(int i=1; i<3; i++) if(n[i] < min) min = n[i];
        if(min == n[0]) printf("Soongsil");
        else if(min == n[1]) printf("Korea");
        else printf("Hanyang");
    }
}