#include <stdio.h>

int main() {
    char c;
    while ((c = getchar()) != EOF) {
        if(c>='a' && c<='z') {
            c = c - 32;
        }

        printf("%c", c);
    }
}