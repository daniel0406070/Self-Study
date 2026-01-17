#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{
    int x;
    int y;
} Point;

Point pivot;

long long ccw(Point a, Point b, Point c) {
    return (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);
}

long long dist2(Point a, Point b) {
    return (long long)(b.x - a.x) * (b.x - a.x) + (long long)(b.y - a.y) * (b.y - a.y);
}

int compare(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    long long c = ccw(pivot, *p1, *p2);
    if (c > 0) return -1;
    else if (c < 0) return 1;
    else {
        long long d1 = dist2(pivot, *p1);
        long long d2 = dist2(pivot, *p2);
        if (d1 < d2) return -1;
        else if (d1 > d2) return 1;
        else return 0;
    }
}

int main() {
    int n, l;
    scanf("%d %d", &n, &l);

    Point *arr = (Point *)malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &arr[i].x, &arr[i].y);
    }
    
    int flag = 1;
    // 모든 점이 일직선
    for (int i = 0; i < n; i++) {
        if (ccw(arr[0], arr[1], arr[i]) != 0) {
            flag = 0;
            break;
        }
    }
    if (flag) {
        long double max_dist = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long d2 = dist2(arr[i], arr[j]);
                if (d2 > max_dist) {
                    max_dist = d2;
                }
            }
        }
        long double border_length = 2 * sqrtl(max_dist) + 2.0 * l * acosl(-1.0);
        printf("%d\n", (int)(border_length + 0.5));
        return 0;
    }

    int min_idx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i].y < arr[min_idx].y || (arr[i].y == arr[min_idx].y && arr[i].x > arr[min_idx].x)) {
            min_idx = i;
        }
    }

    pivot = arr[min_idx];

    for (int i = min_idx; i < n; i++) {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = pivot;

    qsort(arr, n - 1, sizeof(Point), compare);
    // for (int i = 0; i < n; i++) {
    //     printf("%d %d %f\n", arr[i].x, arr[i].y, arr[i].angle);
    // }

    Point *stack = (Point *)malloc((n + 2) * sizeof(Point));
    stack[0] = pivot;
    stack[1] = arr[0];
    int top = 1;

    for (int i = 0; i < n; i++) {
        while (top > 0 && ccw(stack[top - 1], stack[top], arr[i]) <= 0) {
            top--;
        }
        stack[++top] = arr[i];
    }

    // printf("%d\n", top);
    // for (int i = 0; i <= top; i++) {
    //     printf("%d %d\n", stack[i].x, stack[i].y);
    // }

    long double border_length = 0;
    for (int i = 0; i < top; i++) {
        int dx = stack[i + 1].x - stack[i].x;
        int dy = stack[i + 1].y - stack[i].y;
        border_length += sqrtl((long long)dx * dx + (long long)dy * dy);
    }
    border_length += 2.0 * l * acosl(-1.0);
    printf("%d\n", (int)(border_length + 0.5));
}