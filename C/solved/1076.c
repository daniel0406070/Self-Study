#include <stdio.h>
#include <string.h>

char* color[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};

int main(){
    char c[10];
    int a[3];

    for(int i = 0; i < 3; i++){
        scanf("%s", c);
        for(int j = 0; j < 10; j++){
            if(strcmp(c, color[j]) == 0){
                a[i] = j;
                break;
            }
        }
    }

    long long res = a[0] * 10 + a[1];
    for(int i = 0; i < a[2]; i++){
        res *= 10;
    }
    

    printf("%lld\n", res);
    return 0;    
}