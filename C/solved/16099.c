#include <stdio.h>

int main(){
    long long int n,a,b,c,d;
    scanf("%d", &n);
    while(n--){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(a*b>c*d) printf("TelecomParisTech\n");
        else if(a*b<c*d) printf("Eurecom\n");
        else printf("Tie\n");
    }
}