#include <stdio.h>
#include <stdlib.h>
#define MAX 100002

typedef struct meeting *mptr;
typedef struct meeting{
    int start;
    int end;
}meeting;

int cmp(const void *a, const void *b) {
    mptr m1 = (mptr)a;
    mptr m2 = (mptr)b;

    if (m1->end == m2->end) {
        return m1->start - m2->start;
    }
    else {
        return m1->end - m2->end;
    }
}

meeting meet_list[MAX];

int main() {
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++) {
        scanf("%d %d",&meet_list[i].start,&meet_list[i].end);
    }

    qsort(meet_list,n,sizeof(meeting),cmp);

    int count = 1;
    int end = meet_list[0].end;
    
    for (int i = 1; i < n; i++) {
        if (meet_list[i].start >= end) {
            count++;
            end = meet_list[i].end;
        }
    }

    printf("%d",count);
}