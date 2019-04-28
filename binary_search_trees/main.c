#include <stdio.h>
#include<stdlib.h>
#define COUNT 10

struct node {
    int key;
    struct node * left;
    struct node * right;
    int size;
};
struct node* newNode(int key);
struct node* insert(struct node* node, int key);
struct node* search(struct node* root, int key);
int initSize(struct node * root);
void printSize(struct node * root);
void print2DUtil(struct node * root, int space);
int numOfLeafs(struct node * root);


int main() {
    struct node* root = NULL;
    root = insert(root, 4);
    insert(root, 2);
    insert(root, 1);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5);
    print2DUtil(root, 0);
    //printSize(root);
    // printf("\n Minimum value in BST is %d", minValue(root));
    //   getchar();
    printf("Num of leafs: %d \n", numOfLeafs(root));
    return 0;
}

struct node* newNode(int key)
{
    struct node* node = (struct node*)
            malloc(sizeof(struct node));
    node->key  = key;
    node->left  = NULL;
    node->right = NULL;

    return(node);
}
/* Give a binary search tree and a number,
inserts a new node with the given number in
the correct place in the tree. Returns the new
root pointer which the caller should then use
(the standard trick to avoid using reference
parameters). */
struct node* insert(struct node* node, int key)
{
    /* 1. If the tree is empty, return a new,
        single node */
    if (node == NULL)
        return(newNode(key));
    else
    {
        /* 2. Otherwise, recur down the tree */
        if (key <= node->key)
            node->left  = insert(node->left, key);
        else
            node->right = insert(node->right, key);

        /* return the (unchanged) node pointer */
        return node;
    }
}
int numOfLeafs(struct node * root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL ){
        return 1;
    }
    return numOfLeafs(root->left) + numOfLeafs(root->right);
}

// C function to search a given key in a given BST
struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

    // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}
int initSize(struct node * root){
    if(root == NULL){
        return 0;
    }
    int leftSize = initSize(root->left);
    int rightSize = initSize(root->right);
    root->size = leftSize+rightSize +1;
    return root->size;
}

void printSize(struct node * root){
    if(root == NULL){
        return;
    }
    printSize(root->left);
    printf("%d\n", root->size);
    printSize(root->right);
}

void print2DUtil(struct node * root, int space)
{
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += COUNT;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);

    // Process left child
    print2DUtil(root->left, space);
}

