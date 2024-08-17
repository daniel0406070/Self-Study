#include <stdio.h>

int main(){
    int a[4];
    for(int i=0; i<4; i++) scanf("%d", &a[i]);

    if(a[0] == 8 || a[0] == 9){
        if(a[3] == 8 || a[3] == 9){
            if(a[1] == a[2]) printf("ignore\n");
            else printf("answer\n");
        }
        else printf("answer\n");
    }
    else printf("answer\n");

}