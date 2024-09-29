#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    long long int x, y;
} Point;

long long int ccw(Point p1, Point p2, Point p3){
    return (p1.x*p2.y + p2.x*p3.y + p3.x*p1.y) - (p1.y*p2.x + p2.y*p3.x + p3.y*p1.x);
}

int main(){
    int n;
    scanf("%d", &n);

    Point arr[10000];
    for(int i=0; i<n; i++){
        scanf("%lld %lld", &arr[i].x, &arr[i].y);
    }

    long long int sum=0;
    for(int i=1; i<n-1; i++){
        sum+=ccw(arr[0], arr[i], arr[i+1]);
    }
    
    printf("%.1lf\n", labs(sum)/2.0);
}