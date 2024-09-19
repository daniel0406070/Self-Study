#include <stdio.h>

int main(){
    int n;
    char t;
    scanf("%d", &n);

    int c=0,s=0,i=0,a=0;
    for(int j=0;j<n;j++){
        scanf(" %c", &t);
        if(t=='C'){
            c++;
        }else if(t=='S'){
            s++;
        }else if(t=='I'){
            i++;
        }else if(t=='A'){
            a++;
        }
    }

    scanf(" %c", &t);
    if(t=='C'){
        printf("%d\n", c);
    }else if(t=='S'){
        printf("%d\n", s);
    }else if(t=='I'){
        printf("%d\n", i);
    }else if(t=='A'){
        printf("%d\n", a);
    }
}