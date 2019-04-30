#include <stdio.h>
#include <malloc.h>
#define COUNT 10

struct node {
    int key;
    struct node * left;
    struct node * right;

};
struct node * initNode(int key);
int treeHeight(struct node * root);
void print2DUtil(struct node * root, int space);

int main() {
    int numbOfNodes;
    scanf("%d", &numbOfNodes);
    struct node * nodes[numbOfNodes];

    int rootValue;
    scanf("%d", &rootValue);
    nodes[0] = initNode(rootValue);

    for(int i = 1; i < numbOfNodes; i++){
        int root;
        char parrent;
        int key;
     //   scanf("%d %c %d ", &root, &parrent, &key);
        scanf("%d", &root);
        scanf(" %c", &parrent);
        scanf("%d", &key);
        nodes[i] = initNode(key);
        if(parrent == 'L'){
            nodes[root]->left = nodes[i];
        } else{
            nodes[root]->right = nodes[i];
        }
    }
    printf("%d", treeHeight(nodes[0]));

//    print2DUtil(nodes[0], 0);




    return 0;
}

struct node * initNode(int key){
    struct node * node = (struct node * ) malloc(sizeof(struct node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int treeHeight(struct node * root){
    if(root == NULL){
        return -1;
    }
    int leftHeight = treeHeight(root->left) + 1;
    int rightHeight = treeHeight(root->right) + 1;
    return leftHeight > rightHeight ? leftHeight : rightHeight;
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