typedef struct node *nptr;
typedef struct node {
    long long int val;
    int start;
    int end;
    nptr left;
    nptr right;
    long long int lazy;
} node;


nptr root=NULL;

nptr init(int start,int end){
    node* newnode=(node*)malloc(sizeof(node));
    newnode->start=start;
    newnode->end=end;
    newnode->val=0;
    newnode->lazy=0;
    if (start==end){
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    else{
        int mid=(start+end)/2;
        newnode->left=init(start,mid);
        newnode->right=init(mid+1,end);
        return newnode;
    }
}
void lazy_update(nptr* root){
    nptr snode=*root;
    if (snode->lazy!=0){
        snode->val+=snode->lazy*(snode->end-snode->start+1);
        if (snode->start!=snode->end){
            snode->left->lazy+=snode->lazy;
            snode->right->lazy+=snode->lazy;
        }
        snode->lazy=0;
    }
}
void set_val(nptr* root,int idx,long long val){
    if ((*root)&&(*root)->start<=idx && idx<=(*root)->end){
        (*root)->val+=val;
        set_val(&((*root)->left),idx,val);
        set_val(&((*root)->right),idx,val);
    }
}

void update(nptr* root,int start,int end,int val){
    nptr snode=*root;

    lazy_update(root);
    if (snode && snode->start>=start && snode->end<=end){
        snode->val+=val*(snode->end-snode->start+1);
        if (snode->start!=snode->end){
            snode->left->lazy+=val;
            snode->right->lazy+=val;
        }
    }

    else{
        if(snode->left->end>=start) update(&(snode->left),start,end,val);
        if(snode->right->start<=end) update(&(snode->right),start,end,val);
        lazy_update(&(snode->left));
        lazy_update(&(snode->right));

        snode->val=snode->left->val+snode->right->val;
    }
    
}

long long int get_sum(nptr* root,int start,int end){
    nptr snode=*root;
    lazy_update(root);
    if (snode && snode->start>=start && snode->end<=end){
        return snode->val;
    }
    else{
        long long int sum=0;
        if (snode->start!=snode->end){
        sum+=get_sum(&(snode->left),start,end);
        sum+=get_sum(&(snode->right),start,end);
        }
        return sum;
    }
}