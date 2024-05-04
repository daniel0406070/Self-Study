#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);

    int call_time[21];
    for(int i=0; i<n; i++){
        scanf("%d", &call_time[i]);
    }

    int y=0, m=0;
    for(int i=0; i<n; i++){
        y += (call_time[i]/30+1)*10;
        m += (call_time[i]/60+1)*15;
    }

    if(y < m){
        printf("Y %d", y);
    }else if(y > m){
        printf("M %d", m);
    }else{
        printf("Y M %d", y);
    }
}