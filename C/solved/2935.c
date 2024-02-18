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
            for(int i = 1; i < len_a; i++){
                a[i] = '0';
            }
            a[len_a] = '\0';
        }else{
            if(len_a > len_b){
                a[len_a - len_b] = '1';
                for(int i = len_a - len_b + 1; i < len_a; i++)a[i] = '0';
                a[len_a] = '\0';
            }else{
                b[len_b - len_a] = '1';
                for(int i = len_b - len_a + 1; i < len_b; i++) b[i] = '0';
                b[len_b] = '\0';
            }
        }
    }
    
}