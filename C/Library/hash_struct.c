#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000

typedef struct node* nptr;
typedef struct node{
    char name[21];
    nptr next;
    nptr parent;
    int friend_n;
} node;
nptr hash_table[MAX];

void init(){
    for (int i = 0; i < MAX; i++){
        hash_table[i]=NULL;
    }
}

int hash(char c){
    if(c>='A' && c<='Z') return c-'A';
    else return c-'a'+26;
}

int hash2(char* name){
    int sum=0;
    for(int i=0;name[i]!='\0';i++){
        sum+=hash(name[i])*i*500;
    }
    return sum%MAX;
}

nptr insert(char* name){
    int key=hash2(name);
    if (hash_table[key]!=NULL && !strcmp(hash_table[key]->name,name)) return hash_table[key];
    else{
        nptr new_node=(nptr)malloc(sizeof(node));
        strcat(new_node->name,name);
        new_node->next=NULL;
        new_node->parent=new_node;
        new_node->friend_n=1;
        if (!hash_table[key]) hash_table[key]=new_node;
        else{
            nptr cur=hash_table[key];
            while (cur->next!=NULL){
                cur=cur->next;
                if (!strcmp(cur->name,name)) return cur;
            }
            cur->next=new_node;
        }
        return new_node;
    }
}
// 아래는 union-find 부분임
int serach(nptr node){
    nptr cur=find_p(node);
    return cur->friend_n;
}

nptr find_h(char* name){
    int key=hash2(name);
    if (!hash_table[key]) return NULL;
    else{
        nptr cur=hash_table[key];
        while (cur!=NULL){
            if (cur->name==name) return cur;
            cur=cur->next;
        }
        return NULL;
    }
}

nptr find_p(nptr cur){
    if (cur->parent==cur) return cur;
    return find_p(cur->parent);
}

nptr find(char* name){
    int key=hash2(name);
    nptr cur;
    if (!find_h(name)) cur=insert(name);
    return find_p(cur);
}

void merge(nptr x,nptr y){
    nptr x_p=find_p(x);
    nptr y_p=find_p(y);
    if (x_p==y_p) return;
    y_p->parent=x_p;
    x_p->friend_n+=y_p->friend_n;
}