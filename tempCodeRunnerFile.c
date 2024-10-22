#include<stdio.h>
#include<stdlib.h>

#define MAX 3

struct BTreeNode{
    int keys[MAX-1];
    struct BTreeNode* children[MAX];
    int numkeys;
    int leaf;
};

struct BTreeNode* createNode(int leaf)
{
    struct BTreeNode* node = (struct BTreeNode*)malloc(sizeof(struct BTreeNode));
    node->numkeys = 0;
    node->leaf = leaf;
    for(int i=0;i<MAX;i++)
    {
        node->children[i]= NULL;
    }
    return node;
}

void traversal(struct BTreeNode* root)
{
    if(root==NULL)   return;
    int i;

    for(i=0;i<root->numkeys;i++)
    {
        if(!root->leaf)
        {
            traversal(root->children[i]);
        }
        printf("%d ",root->keys[i]);
    }

    if(!root->leaf)
    {
        traversal(root->children[i]);
    }
}

void splitChild(struct BTreeNode* parent, int i) {
    struct BTreeNode* child = parent->children[i];
    struct BTreeNode* newNode = createNode(child->leaf);
    newNode->numkeys = MAX / 2;

    for (int j = 0; j < MAX / 2; j++) {
        newNode->keys[j] = child->keys[j + MAX / 2 + 1];
    }

    if (!child->leaf) {
        for (int j = 0; j <= MAX / 2; j++) {
            newNode->children[j] = child->children[j + MAX / 2 + 1];
        }
    }

    child->numkeys = MAX / 2;

    for (int j = parent->numkeys; j >= i + 1; j--) {
        parent->children[j + 1] = parent->children[j];
    }
    parent->children[i + 1] = newNode;

    for (int j = parent->numkeys - 1; j >= i; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[i] = child->keys[MAX / 2];
    parent->numkeys++;
}


void insertNonFull(struct BTreeNode* node,int key)
{
    int i = node->numkeys - 1;
    if(node->leaf)
    {
        while(i>=0 && node->keys[i]>key)
        {
            node->keys[i+1] = node->keys[i];
            i--;
        }
        node->keys[i+1] = key;
        node->numkeys++;
    }
    else{
        while(i>=0 && node->keys[i]>key){
            i--;
        }

        i++;

        if(node->children[i]->numkeys==MAX-1)
        {
            splitChild(node,i);

            if(key>node->keys[i]){
                i++;
            }
        }
        insertNonFull(node->children[i],key);
    }
}


void insert(struct BTreeNode** root,int key)
{
    struct BTreeNode* node = *root;
    if(node->numkeys==MAX-1)
    {
        struct BTreeNode* newNode = createNode(0);
        newNode->children[0] = node;
        splitChild(newNode,0);
        insertNonFull(newNode,key);
        *root = newNode;
    }
    else{
        insertNonFull(node,key);
    }
}

int main()
{
    struct BTreeNode* root = createNode(1);

    insert(&root,1);
    insert(&root,2);
    insert(&root,3);
    insert(&root,4);
    insert(&root,5);
    insert(&root,6);
    insert(&root,7);
    insert(&root,8);
    insert(&root,9);
    insert(&root,10);

    traversal(root);

    return 0;
}
