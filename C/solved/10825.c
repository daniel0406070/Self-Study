#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char name[11];
    int kor;
    int eng;
    int math;
} Student;

int cmp(const void* a, const void* b){
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;

    if (s1->kor == s2->kor){
        if (s1->eng == s2->eng){
            if (s1->math == s2->math){
                return strcmp(s1->name, s2->name);
            }
            return s2->math - s1->math;
        }
        return s1->eng - s2->eng;
    }
    return s2->kor - s1->kor;
}

int main(){
    int n;
    scanf("%d", &n);
    Student* students = (Student*)malloc(sizeof(Student) * n);
    
    for (int i = 0; i < n; i++){
        scanf("%s %d %d %d", students[i].name, &students[i].kor, &students[i].eng, &students[i].math);
    }
    qsort(students, n, sizeof(Student), cmp);

    for (int i = 0; i < n; i++){
        printf("%s\n", students[i].name);
    }

}