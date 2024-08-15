#include <stdio.h>

int main(){
    int a[4];
    for(int i=0; i<4; i++) scanf("%d", &a[i]);

    if(a[0]<a[1] && a[1]<a[2] && a[2]<a[3]) printf("Fish Rising");
    else if(a[0]>a[1] && a[1]>a[2] && a[2]>a[3]) printf("Fish Diving");
    else if(a[0]==a[1] && a[1]==a[2] && a[2]==a[3]) printf("Fish At Constant Depth");
    else printf("No Fish");
}