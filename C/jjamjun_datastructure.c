#define MAX_SIZE 50
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

// 구조체 선언
typedef struct {
    int data;
}element;

typedef struct node* nodePointer;
typedef struct node {
    nodePointer leftnext;
    element data;
    nodePointer rightnext;
}node;

// 함수 선언
void insertNode(nodePointer* node, nodePointer newnode);
void printNODE_left(nodePointer h);
void printNODE_right(nodePointer h);
void mergeNODE(nodePointer* a, nodePointer* b);

int main(void) {
    FILE* fp1 = fopen("in1.txt", "r");
    FILE* fp2 = fopen("in2.txt", "r");

    nodePointer NODE1=NULL;
    nodePointer NODE2=NULL;

    int input;

    while (fscanf(fp1, "%d", &input) != EOF) {
        nodePointer temp;
        temp = (nodePointer)malloc(sizeof(struct node));
        element data_element;
        data_element.data = input;

        temp->leftnext = temp;
        temp->rightnext = temp;
        temp->data = data_element;

        insertNode(&NODE1, temp);
    }

    while (fscanf(fp2, "%d", &input) != EOF) {
        nodePointer temp;
        temp = (nodePointer)malloc(sizeof(struct node));
        element data_element;
        data_element.data = input;

        temp->leftnext = temp;
        temp->rightnext = temp;
        temp->data = data_element;

        insertNode(&NODE2, temp);
    }

    printNODE_left(NODE1);
    printNODE_right(NODE1);
    printNODE_left(NODE2);
    printNODE_right(NODE2);

    mergeNODE(&NODE1, &NODE2);

    printNODE_left(NODE1);
    printNODE_right(NODE1);
}

void insertNode(nodePointer* root, nodePointer newnode) {
    nodePointer node = *root;
    if (!node) {
        *root = newnode;
        return;
    }
    newnode->leftnext = node;
    newnode->rightnext = node->rightnext;
    node->rightnext->leftnext = newnode;
    node->rightnext = newnode;
}

void printNODE_left(nodePointer h) {
    nodePointer current = h->leftnext;

    printf("%d ", h->data.data);
    while (current != h) {
        printf("%d ", current->data.data);
        current = current->leftnext;
    }
    printf("\n");
}

void printNODE_right(nodePointer h) {
    nodePointer current = h->rightnext;

    while (current != h) {
        printf("%d ", current->data.data);
        current = current->rightnext;
    }
    printf("%d ", h->data.data);
    printf("\n");
}

void mergeNODE(nodePointer* ta, nodePointer* tb) {
    nodePointer a = *ta;
    nodePointer b = *tb;
    nodePointer temp;


    a->rightnext->leftnext = b;
    b->rightnext->leftnext = a;
    temp = a->rightnext;
    a->rightnext = b->rightnext;
    b->rightnext = temp;
}