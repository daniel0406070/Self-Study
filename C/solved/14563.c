#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        int tmp;
        scanf("%d",&tmp);
        if(tmp==1){
            printf("Deficient\n");
            continue;
        }

        int sum=1;

        for(int j=2;j<tmp;j++){
            if(tmp%j==0) sum+=j;
        }

        if(sum==tmp) printf("Perfect\n");
        else if(sum<tmp) printf("Deficient\n");
        else printf("Abundant\n");
    }
}