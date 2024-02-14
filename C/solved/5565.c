#include <stdio.h>

int main(){
    int total, book;
    scanf("%d", &total);

    for(int i = 0; i < 9; i++){
        scanf("%d", &book);
        total -= book;
    }

    printf("%d", total);
}