#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);

    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        char str[100];
        int c;
        double a,sum=0;
        for(int j=0;j<n;j++){
            scanf("%s %d %lf",str,&c,&a);
            sum+=c*a;
        }

        printf("$%.2lf\n",sum);
    }
}