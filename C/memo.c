#include <stdio.h>

int main(){
    int a=0b11111;

    int cnt;
    for(int i=0; i<=a; i++){
        cnt=0;
        for(int j=1; j<=a; j<<=1){
            if(i&j) cnt++;
        }
        if(cnt<=3){ 
            for(int j=1; j<=a; j<<=1){
                if(i&j) printf("1");
                else printf("0");
            }
        printf("\n");
    }
}
}



