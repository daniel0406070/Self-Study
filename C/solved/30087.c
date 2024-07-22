#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char seminar[8][35] = {"Algorithm", "DataAnalysis", "ArtificialIntelligence", "CyberSecurity", "Network", "Startup", "TestStrategy"};
    char classroom[8][5] = {"204", "207", "302", "B101", "303", "501", "105"};
    char input[20];
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%s", input);
        for(int j = 0; j < 7; j++){
            if(strcmp(input, seminar[j]) == 0){
                printf("%s\n", classroom[j]);
                break;
            }
        }
    }

}