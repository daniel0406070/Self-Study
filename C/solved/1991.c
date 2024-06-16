#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *nptr;
typedef struct node{
    char data;
    char left;
    char right;
} node;

nptr store[26];

void preorder(nptr root){
    if(root){
        printf("%c", root->data);
        preorder(store[root->left]);
        preorder(store[root->right]);
    }
}

void inorder(nptr root){
    if(root){
        inorder(store[root->left]);
        printf("%c", root->data);
        inorder(store[root->right]);
    }
}

void postorder(nptr root){
    if(root){
        postorder(store[root->left]);
        postorder(store[root->right]);
        printf("%c", root->data);
    }
}



int main(){
    int n;
    scanf("%d", &n);
    char data, left, right;
    for(int i = 0; i < n; i++){
        scanf(" %c %c %c", &data, &left, &right);
        store[data-'A'] = (nptr)malloc(sizeof(node));
        store[data-'A']->data = data;
        store[data-'A']->left = left-'A';
        store[data-'A']->right = right-'A';
    }
    preorder(store[0]);
    printf("\n");
    inorder(store[0]);
    printf("\n");
    postorder(store[0]);
}