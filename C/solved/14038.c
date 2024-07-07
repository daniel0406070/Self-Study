#include <stdio.h>

int main(){
    int w=0;
    char c;

    for(int i = 0; i < 6; i++){
        scanf(" %c", &c);
        if(c == 'W') w++;
    }

    if(w>=5) printf("1");
    else if(w>=3) printf("2");
    else if(w>=1) printf("3");
    else printf("-1");
}