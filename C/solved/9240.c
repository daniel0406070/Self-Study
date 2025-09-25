#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{
    int x;
    int y;
    double angle;
} Point;

long long ccw(Point a, Point b, Point c) {
    return (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);
}

long long cccw(Point a, Point b, Point c, Point d) {
    return (long long)(b.x - a.x) * (d.y - c.y) - (long long)(b.y - a.y) * (d.x - c.x);
}

int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    if (p1->angle < p2->angle) return -1;
    else if (p1->angle > p2->angle) return 1;
    else {
        if (p1->y < p2->y) return -1;
        else if (p1->y > p2->y) return 1;
        else {
            if (p1->x < p2->x) return -1;
            else if (p1->x > p2->x) return 1;
            else return 0;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    Point *arr = (Point *)malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }

    if(n==2){
        printf("%f\n",sqrt((arr[0].x-arr[1].x)*(arr[0].x-arr[1].x)+(arr[0].y-arr[1].y)*(arr[0].y-arr[1].y)));
        return 0;
    }
    
    int min_idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].y < arr[min_idx].y || (arr[i].y == arr[min_idx].y && arr[i].x > arr[min_idx].x)) {
            min_idx = i;
        }
    }

    int pivot[2] = {arr[min_idx].x, arr[min_idx].y};

    for (int i = min_idx; i < n; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = (Point){pivot[0], pivot[1], 0.0};


    for (int i = 0; i < n - 1; i++) {
        arr[i].angle = atan2(arr[i].y - pivot[1], arr[i].x - pivot[0]);
    }

    qsort(arr, n - 1, sizeof(Point), compare);
    // for (int i = 0; i < n; i++) {
    //     printf("%d %d %f\n", arr[i].x, arr[i].y, arr[i].angle);
    // }

    int flag=1;
    for(int i=1;i<n-1;i++){
        if(arr[i].angle != arr[i-1].angle){
            flag=0;
            break;
        }
    }

    if(flag){
        int max_dist_idx=0;
        for(int i=1;i<n-1;i++){
            if((arr[i].x - pivot[0])*(arr[i].x - pivot[0]) + (arr[i].y - pivot[1])*(arr[i].y - pivot[1]) > (arr[max_dist_idx].x - pivot[0])*(arr[max_dist_idx].x - pivot[0]) + (arr[max_dist_idx].y - pivot[1])*(arr[max_dist_idx].y - pivot[1])){
                max_dist_idx = i;
            }
        }
        printf("%f\n",sqrt((arr[max_dist_idx].x - pivot[0])*(arr[max_dist_idx].x - pivot[0]) + (arr[max_dist_idx].y - pivot[1])*(arr[max_dist_idx].y - pivot[1])));
        return 0;
    }

    Point *stack = (Point *)malloc((n + 2) * sizeof(Point));
    stack[0] = (Point){pivot[0], pivot[1], 0.0};
    stack[1] = arr[0];
    int top = 1;

    for (int i = 0; i < n; i++) {
        while (top > 0 && ccw(stack[top - 1], stack[top], arr[i]) <= 0) {
            top--;
        }
        stack[++top] = arr[i];
    }

    int a,b,c,d;
    int longest_a=-1, longest_b=-1;
    double dist_ac=-1;

    a=0;
    c=a+1;

    double dist(int idx1, int idx2){
        return (stack[idx1].x - stack[idx2].x) * (stack[idx1].x - stack[idx2].x) + (stack[idx1].y - stack[idx2].y) * (stack[idx1].y - stack[idx2].y);
    }

    while(1){
        if(cccw(stack[a],stack[(a+1)%top],stack[c],stack[(c+1)%top])>=0){
            c = (c+1)%top;
        }
        else{
            a = (a+1)%top;
        }

        if(a==longest_a && c==longest_b) break;

        double tmp = dist(a,c);
        if(tmp>dist_ac){
            dist_ac = dist(a,c);
            longest_a = a;
            longest_b = c;
        }
    }

    printf("%f\n",sqrt(dist_ac));
}