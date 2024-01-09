#include <stdio.h> 

int main(){
    char all[6][4][20]={
        {"SHIP NAME", "CLASS", "DEPLOYMENT", "IN SERVICE"},
        {"N2 Bomber", "Heavy Fighter", "Limited", "21"},
        {"J-Type 327", "Light Combat", "Unlimited", "1"},
        {"NX Cruiser", "Medium Fighter", "Limited", "18"},
        {"N1 Starfighter", "Medium Fighter", "Unlimited", "25"},
        {"Royal Cruiser", "Light Combat", "Limited", "4"},
    };
    
    for(int i=0; i<6; i++){
        for(int j=0; j<2; j++){
            printf("%-15s", all[i][j]);
        }
        printf("%-11s", all[i][2]);
        printf("%-10s", all[i][3]);
        printf("\n");
    }
}