#include <stdio.h>

int arr1[1000002];
int arr2[1000002];

int main(){
    int n,m;
    scanf("%d %d", &n, &m);

    for(int i=0; i<n; i++) scanf("%d", &arr1[i]);
    for(int i=0; i<m; i++) scanf("%d", &arr2[i]);

    int i=0, j=0;
    while(i<n && j<m){
        if(arr1[i] < arr2[j]) printf("%d ", arr1[i++]);
        else printf("%d ", arr2[j++]);
    }

    while(i<n) printf("%d ", arr1[i++]);
    while(j<m) printf("%d ", arr2[j++]);

}