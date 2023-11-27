#include <stdio.h>

int main(){
    int n;
    int one=0,zero=0;
    int temp;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&temp);
        if(temp==1) one++;
        else zero++;
    }

    if(one>zero) printf("Junhee is cute!");
    else printf("Junhee is not cute!");
}