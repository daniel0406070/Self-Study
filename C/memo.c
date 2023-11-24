#include <stdio.h>
#include <math.h>

typedef struct test *testPtr;
typedef struct test{
    int a; // 인자
    int b; // 인자
    testPtr next; // 자신의 포인터를 인자로 가진다.
} test;

int main(){
    test num;

    test.a = 1;
    (&test)->b = 2;
}


