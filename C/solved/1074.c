#include <stdio.h>
#include <math.h>

int find(int n, int r, int c){
    int result = 0;
    if (n==1){
        if (r==0){
            if (c==0) return 0;
            else return 1;
        }
        else {
            if (c==0) return 2;
            else return 3;
        }
    }

    int a = pow(2, n-1);
    if (r < a){
        if (c < a){
            result += find(n-1, r, c);
        }
        else{
            result += a*a;
            result += find(n-1, r, c-a);
        }
    }
    else{
        if (c < a){
            result += 2*a*a;
            result += find(n-1, r-a, c);
        }
        else{
            result += 3*a*a;
            result += find(n-1, r-a, c-a);
        }
    }
    return result;
}

int main(){
    int n,r,c;
    scanf("%d %d %d", &n, &r, &c);

    printf("%d\n", find(n, r, c))-1;

}