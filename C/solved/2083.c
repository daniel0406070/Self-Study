#include <stdio.h>

int main(){
    char name[20];
    int age, weight;

    scanf("%s %d %d", name, &age, &weight);
    while (name[0] != '#' && age != 0 && weight != 0)
    {
        printf("%s ", name);
        if (age > 17 || weight >= 80)
            printf("Senior\n");
        else
            printf("Junior\n");

        scanf("%s %d %d", name, &age, &weight);
    }
}