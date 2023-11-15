#include <stdio.h>

int main(){
    int n,l;
    scanf("%d %d", &n, &l);

    int max=0;
    int max_count=0;

    for(int i=0; i<n; i++){
        int tmp=0;
        char c[1002];
        scanf("%s", c);

        int black=0;

        for(int j=0; c[j]!='\0'; j++){
            if(c[j]=='1') black=1;
            else{
                if(black==1) tmp++;
                black=0;
            }
        }
        if(black==1) tmp++;

        if(max<tmp){
            max=tmp;
            max_count=1;
        }
        else if(max==tmp) max_count++;
    }

    printf("%d %d", max, max_count);
}