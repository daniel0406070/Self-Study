#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node *treeptr;
typedef struct node{
	char item[1000];
	treeptr left;
	treeptr right;
} tnode;

treeptr root = NULL;

void divide_by_plusminus(treeptr* node){
	treeptr tmp = *node;
	int len=strlen(tmp->item);
	int bracket=0;
	if (len==1) return;
	for (int i=len-1; i>=0; i--){
		if (tmp->item[i]=='(') bracket++;
		else if (tmp->item[i]==')') bracket--;
		if ((tmp->item[i]=='+' || tmp->item[i]=='-') && bracket==0){
			tmp->left = (treeptr)malloc(sizeof(tmp));
			tmp->right = (treeptr)malloc(sizeof(tmp));
			strncpy(tmp->left->item,tmp->item,i);
			strncpy(tmp->right->item,tmp->item+i+1,len-i-1);
			tmp->left->item[i]='\0';
			tmp->right->item[len-i-1]='\0';
			tmp->left->left = NULL;
			tmp->left->right = NULL;
			tmp->right->left = NULL;
			tmp->right->right = NULL;
			
			to_do(&(tmp->right));
			to_do(&(tmp->left));
			
			if (tmp->item[i]=='+') tmp->item[0]='+';
			else tmp->item[0]='-';
			tmp->item[1]='\0';
			*node = tmp;
			break;
		}
	}
}


void divide_by_multdiv(treeptr* node){
	treeptr tmp = *node;
	int len=strlen(tmp->item);
	int bracket=0;
	if (len==1) return;
	for (int i=len-1; i>=0; i--){
		if (tmp->item[i]=='(') bracket++;
		else if (tmp->item[i]==')') bracket--;
		if ((tmp->item[i]=='*' || tmp->item[i]=='/') && bracket==0){
			tmp->left = (treeptr)malloc(sizeof(tmp));
			tmp->right = (treeptr)malloc(sizeof(tmp));
			strncpy(tmp->left->item,tmp->item,i);
			strncpy(tmp->right->item,tmp->item+i+1,len-1-i);
			tmp->left->item[i]='\0';
			tmp->right->item[len-i-1]='\0';
			tmp->left->left = NULL;
			tmp->left->right = NULL;
			tmp->right->left = NULL;
			tmp->right->right = NULL;
			to_do(&(tmp->right));
			to_do(&(tmp->left));
			
			
			if (tmp->item[i]=='*') tmp->item[0]='*';
			else tmp->item[0]='/';
			tmp->item[1]='\0';
			*node = tmp;
			break;
		}
	}
}

void erase_bracket(treeptr* node){
	treeptr tmp = *node;
	int len=strlen(tmp->item);
	int bracket=0;
	if (len==1) return;
	for (int i=0; i<len-1; i++){
		if (tmp->item[i]=='(') bracket++;
		else if (tmp->item[i]==')') bracket--;
		if (bracket==0) return;
	}
	if (tmp->item[0]=='(' && tmp->item[len-1]==')'){
		strncpy(tmp->item,tmp->item+1,len-2);
		tmp->item[len-2]='\0';
		erase_bracket(&tmp);
	}
	*node = tmp;
}

void to_do(treeptr* node){
	erase_bracket(node);
	divide_by_plusminus(node);
	divide_by_multdiv(node);
}

treeptr postfix(treeptr node){
	if (node->left!=NULL) postfix(node->left);
	if (node->right!=NULL) postfix(node->right);
	printf("%s", node->item);
}


int main(){
	char input[1000];
	scanf("%s", input);
	root = (treeptr)malloc(sizeof(tnode));
	strcpy(root->item,input);
	root->left = NULL;
	root->right = NULL;
	to_do(&root);
	postfix(root);
}
