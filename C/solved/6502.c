#include <stdio.h>

int main(){
    int a,b,c;

    int i = 1;
    while(1){
        scanf("%d", &a);
        if(a == 0){
            break;
        }

        scanf("%d %d", &b, &c);
        

        if(b*b + c*c <= a*a*4){
            printf("Pizza %d fits on the table.\n", i++);
        }
        else{
            printf("Pizza %d does not fit on the table.\n", i++);
        }
        
    }
}