#include <stdio.h>
#include <stdlib.h>
#define MAX 100002

int cmp(const void *a, const void *b) {
    int *m1 = (int *)a;
    int *m2 = (int *)b;

    if (m1[1] == m2[1]) {
        return m1[0] - m2[0];
    }
    else {
        return m1[1] - m2[1];
    }
}

int meet_list[MAX][2];

int main() {
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d",&meet_list[i][0],&meet_list[i][1]);
    }

    qsort(meet_list,n,sizeof(meet_list[0]),cmp);

    int count = 1;
    int end = meet_list[0][1];
    
    for (int i = 1; i < n; i++) {
        if (meet_list[i][0] >= end) {
            count++;
            end = meet_list[i][1];
        }
    }

    printf("%d",count);
}