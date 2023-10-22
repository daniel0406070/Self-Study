#include <stdio.h>

char *day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
int month[12]= {31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    int x,y;
    scanf("%d %d", &x, &y);

    int days = 0;
    for (int i=0;i<x-1;i++) days += month[i-1];
    days += y;

    printf("%s", day[days%7]);
}