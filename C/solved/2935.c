#include <stdio.h>
#include <string.h>

int main(){
    char a[101], b[101], op;
    scanf("%s %c %s", a, &op, b);

    int len_a = strlen(a);
    int len_b = strlen(b);

    if(op == '+'){
        if(len_a == len_b){
            a[0] = '2';
            printf("%s", a);
        }
        else{
            if(len_a > len_b){
                a[len_a - len_b] = '1';
                printf("%s", a);
            }
            else{
                b[len_b - len_a] = '1';
                printf("%s", b);
            }
        }
    }
    else{
        printf("1");
        for(int i = 0; i < len_a + len_b - 2; i++){
            printf("0");
        }
    }
}