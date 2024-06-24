#include <stdio.h>

char mobis[5] = {'M', 'O', 'B', 'I', 'S'};
int mobis_count[5] = {0, 0, 0, 0, 0};

int main(){
    char str[105];
    scanf("%s", str);

    for(int i = 0; str[i] != '\0'; i++){
        for(int j = 0; j < 5; j++){
            if(str[i] == mobis[j]){
                mobis_count[j]++;
                break;
            }
        }
    }

    for(int i = 0; i < 5; i++){
        if(!mobis_count[i]){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

}