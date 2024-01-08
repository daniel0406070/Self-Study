#include <stdio.h>

int main(){
    int white=0;
    char tmp[10];

    for (int i = 0; i < 8; i++)
    {
        scanf("%s",tmp);
        for (int j = 0; j < 8; j++)
        {
            if((i+j)%2==0 && tmp[j]=='F') white++;
        }
    }

    printf("%d",white);
}