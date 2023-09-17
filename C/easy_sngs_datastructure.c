#define _CRT_SECURE_NO_WARNINGS // scanf 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 500 

typedef int iType; // iType은 int형을 가리키는 typedef
typedef struct {   // element는 key와 item을 가지고 있는 구조체
   int key;
   iType item;
} element;


typedef struct node *treePointer; // treePointer는 node를 가리키는 포인터
typedef struct node { // node는 element(key와 item)와 leftChild, rightChild를 가지고 있는 구조체
   element data;
   treePointer leftChild, rightChild;
} tNode; // tNode는 node를 가리키는 typedef
treePointer root = NULL; // 포인터 root를 NULL로 초기화

void insert(treePointer* node, int k, iType theItem); //insert 함수를 선정의
element* search(treePointer root, int k); // search 함수를 선정의
treePointer modifiedSearch(treePointer node, int k); // modifiedSearch 함수를 선정의
void inorder(treePointer ptr); // inorder 함수를 선정의

int main() {
   int n, item, search_key;
   unsigned int seed; //부호없는 정수형 변수 seed 선언

   printf("random number generation (1 ~ %d)\n", MAX_SIZE);
   printf("%s", "the number of nodes in BST (less than and equal to 50) : ");
   scanf("%d", &n);
   printf("%s", "seed : ");
   scanf("%u", &seed);

   printf("\ncreating a BST from random numbers\n");
   srand(seed); // seed를 이용
   printf("generating number : ");

   for (int i = 0; i < n; i++) {
      item = rand() % MAX_SIZE + 1; // 1 ~ MAX_SIZE 사이의 난수 생성
      printf("%3d ", item);
      insert(&root, item, item); // insert 함수 호출
   }
   puts("");


   printf("the key to search : ");
   scanf("%d", &search_key);
   printf("the search process :   ");

   element* result = search(root, search_key);

   if (result)      printf("\nthe element is in BST\n");
   else         printf("\nthe item not found\n");
   puts("");

   printf("inorder traversal of the BST shows the sorted sequence\n");
   inorder(root);

   return 0;
}

void insert(treePointer* node, int k, iType theItem) { // insert 함수 정의하며 이중포인터 node, int형 k, iType형 theItem을 매개변수로 받음
   treePointer ptr, temp = modifiedSearch(*node, k); //포인터 ptr과 temp를 modifiedSearch 함수로 주소를 잡아줌
   
   if ((temp) || !(*node)) { // temp가 NULL이 아니거나 node가 NULL이면
      ptr = malloc(sizeof(*ptr)); // ptr에 동적할당
      ptr->data.key = k; // ptr의 key에 k를 대입
      ptr->data.item = theItem; // ptr의 item에 theItem을 대입
      ptr->leftChild = ptr->rightChild = NULL; // ptr의 leftChild와 rightChild를 NULL로 초기화
      if (*node) // node가 NULL이 아니면
         if (k < temp->data.key) temp->leftChild = ptr; // k가 temp의 key보다 작으면 temp의 leftChild에 ptr을 대입
         else if (k > temp->data.key) temp->rightChild = ptr; // k가 temp의 key보다 크면 temp의 rightChild에 ptr을 대입
         else temp= ptr;
      else *node = ptr; // node가 NULL이면 node에 ptr을 대입
   }
}

element* search(treePointer root, int k) {
   if (!root) return NULL;
   printf("%d => ", root->data.key);
   if (k == root->data.key) return &(root->data);
   if (k < root->data.key)
      return search(root->leftChild, k);
   return search(root->rightChild, k);
}

treePointer modifiedSearch(treePointer node, int k) { // modifiedSearch 함수 정의하며 포인터 node와 int형 k를 매개변수로 받음
   if (!node) // node가 NULL이면 NULL을 반환
      return NULL;
   else {
      while (node) { // node가 NULL이 아니면
         if (!node->leftChild && !node->rightChild) // node의 leftChild와 rightChild가 NULL이면 node를 반환
            return node;
         if (node->data.key > k){ // node의 key가 k보다 크면 node를 leftChild로 이동
            if (node->leftChild) // node의 leftChild가 NULL이 아니면 node를 leftChild로 이동
               node = node->leftChild;
            else {// node의 leftChild가 NULL이면 NULL을 반환
                treePointer tempnode;
                tempnode = malloc(sizeof(*node));
                tempnode->data.key = k;
                tempnode->data.item = k;
                tempnode->leftChild = tempnode->rightChild = NULL;
                node->leftChild=tempnode;
                node = node->leftChild;
            }
            
         }  
         else if (node->data.key < k){  // node의 key가 k보다 작으면 node를 rightChild로 이동
            if (node->rightChild) // node의 rightChild가 NULL이 아니면 node를 rightChild로 이동
               node = node->rightChild;
            else{
                treePointer tempnode;
                tempnode = malloc(sizeof(*node));
                tempnode->data.key = k;
                tempnode->data.item = k;
                tempnode->leftChild = tempnode->rightChild = NULL;
                node->rightChild=tempnode;
                node = node->rightChild;
            }
            
         }
         else // node의 key가 k와 같으면 NULL을 반환
            return NULL;
      }
   }
}

void inorder(treePointer ptr) {
   if (ptr) {
      inorder(ptr->leftChild);
      printf("%3d ", ptr->data.item);
      inorder(ptr->rightChild);
   }
}