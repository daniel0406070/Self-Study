#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *nodeptr;
typedef struct node{
    int end;
    nodeptr child[10];
} tnode;
nodeptr root=NULL;

void insert(nodeptr* root,char *s){
    nodeptr node=*root;
    int len=strlen(s);
    for (int i=0;i<len-1;i++){
        if(node->child[s[i]-'0']==NULL){
            nodeptr nnd;
            nnd = (tnode*)malloc(sizeof(tnode));
            nnd->end=0;
            for (int j = 0; j < 10; j++)
            {
                nnd->child[j]=NULL;
            }
            node->child[s[i]-'0']=nnd;
            node=node->child[s[i]-'0'];
        }
        else{
            node=node->child[s[i]-'0'];
        }
    }
    if(node->child[s[len-1]-'0']==NULL){
        nodeptr nnd;
        nnd = (tnode*)malloc(sizeof(tnode));
        nnd->end=1;
        for (int j = 0; j < 10; j++)
        {
            nnd->child[j]=NULL;
        }
        node->child[s[len-1]-'0']=nnd;
    }
    else{
        node=node->child[s[len-1]-'0'];
        node->end=1;
    }
}