#include <stdio.h>

int main(){
    int n;
    int a[3];
    scanf("%d", &n);

    printf("Gnomes:\n");
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++) scanf("%d", &a[j]);
        if(a[0]<a[1] && a[1]<a[2]) printf("Ordered\n");
        else if(a[0]>a[1] && a[1]>a[2]) printf("Ordered\n");
        else printf("Unordered\n");
    }
}