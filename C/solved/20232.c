#include <stdio.h>

char* arr[50]={"ITMO", "SPbSU", "SPbSU", "ITMO", "ITMO",
    "SPbSU", "ITMO", "ITMO", "ITMO", "ITMO",
    "ITMO", "PetrSU, ITMO", "SPbSU", "SPbSU",
    "ITMO", "ITMO", "ITMO", "ITMO", "SPbSU",
    "ITMO", "ITMO", "ITMO", "ITMO", "SPbSU", "ITMO"};

int main(){
    int n;
    scanf("%d", &n);

    printf("%s\n", arr[n-1995]);
}