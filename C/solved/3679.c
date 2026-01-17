#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Point{
    int x;
    int y;
    int index;
} Point;

long long ccw(Point a, Point b, Point c) {
    return (long long)(b.x - a.x) * (c.y - a.y) - (long long)(b.y - a.y) * (c.x - a.x);
}

long long dist2(Point a, Point b) {
    return (long long)(b.x - a.x) * (b.x - a.x) + (long long)(b.y - a.y) * (b.y - a.y);
}

Point pivot;
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
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);

        Point *arr = (Point *)malloc(n * sizeof(Point));
        for (int i = 0; i < n; i++) {
            scanf("%d %d ", &arr[i].x, &arr[i].y);
            arr[i].index = i;
        }
        
        int min_idx = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i].y < arr[min_idx].y || (arr[i].y == arr[min_idx].y && arr[i].x > arr[min_idx].x)) {
                min_idx = i;
            }
        }

        pivot = arr[min_idx];
        arr[min_idx] = arr[n - 1];
        n--;

        qsort(arr, n, sizeof(Point), compare);
        
        int ptr = n - 1;
        while (ptr > 0 && ccw(pivot, arr[n - 1], arr[ptr - 1]) == 0) {
            ptr--;
        }
        
        int left = ptr, right = n - 1;
        while (left < right) {
            Point temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }

        printf("%d", pivot.index);
        for (int i = 0; i < n; i++) {
            printf(" %d", arr[i].index);
        }
        if (t != 0)
            printf("\n");
    
    }
}