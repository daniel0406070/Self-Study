#include <stdio.h>

int main(){
    for (int t = 0; t < 3; t++)
    {
        int a=0,b=0,tmp;
        for(int i=0; i<4; i++){
            scanf("%d",&tmp);

            if(tmp) a++;
            else b++;
        }

        if(b==0)
            printf("E\n");
        else
            printf("%c\n",'A'+b-1);
        
        
    }
}