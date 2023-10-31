#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node *nptr;
typedef struct node{
    char data;
    struct node *left;
    struct node *right;
}node;

nptr stack[100];
int top=-1;

void push(nptr np){
    stack[++top]=np;
}

nptr pop(){
    return stack[top--];
}

void insert(char data){
    nptr np=(nptr)malloc(sizeof(node));
    np->data=data;
    np->left=NULL;
    np->right=NULL;

    if(isalpha(data)) push(np);
    else if (data=='~') {
        np->right=pop();
        push(np);
    }
    else{
        np->right=pop();
        np->left=pop();
        push(np);
    }
}

void show_tree(nptr np){
    if(np){
        if(np->left||np->right) {
            show_tree(np->left);
            show_tree(np->right);
        }
        printf("%c", np->data);
    }
    else printf("x");
}

int main(){
    char str[100]={0,};
    scanf("%s", str);

    for(int i=0; str[i]!='\0'; i++){
        insert(str[i]);
    }

    show_tree(stack[top]);


}