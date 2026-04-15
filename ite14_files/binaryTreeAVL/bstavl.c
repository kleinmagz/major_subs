#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    int height;
    struct node * left;
    struct node * right;
} Node;

Node * createNode(int data) {
    Node * newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("ERROR: Failed to allocate memory.\n");
        return NULL;
    }

    newNode->data = data;
    newNode->height = 0;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int updateNodeHeight(Node * root) {
    int leftHeight;
    int rightHeight;
    if(root == NULL) {
        return -1;
    }

    leftHeight = updateNodeHeight(root->left);
    rightHeight = updateNodeHeight(root->right);

    if(leftHeight > rightHeight)
        return 1 + leftHeight;
    else if(leftHeight < rightHeight)
        return 1 + rightHeight;
    else
        return 1 + leftHeight;
}

Node * insert(Node * root, int data) {
    if(root == NULL) {
        Node * newNode = createNode(data);
        newNode->height = updateNodeHeight(newNode);
        return newNode;
    }
    if(data > root->data) {
        root->right = insert(root->right, data);
    }
    else if(data < root->data) {
        root->left = insert(root->left, data);
    }
    root->height = updateNodeHeight(root);
    return root;
}

int findMax(Node * root) {
    Node * curr = root;
    while(curr->right != NULL) {
        curr = curr->right;
    }
    return curr->data;
}



int isAVLTree(Node * root) {
    int leftHeight, rightHeight, balance;

    if(root== NULL)
        return 1;

    if(root->left == NULL)
        leftHeight = -1;
    else
        leftHeight = root->left->height;

    if(root->right == NULL)
        rightHeight = -1;
    else
        rightHeight = root->right->height;
    
    balance = leftHeight - rightHeight;

    if(balance > 1 || balance < -1)
        return 0;
    
    return isAVLTree(root->left) && isAVLTree(root->right);
    
}

void leftRotation(Node ** root) {
    Node * oldRoot = *root;
    Node * rightNode = oldRoot->right;
    Node * subTree = rightNode->left;

    rightNode->left = oldRoot;
    oldRoot->right = subTree;
    *root = rightNode;
}

void rightRotation(Node ** root) {
    Node * oldRoot = *root;
    Node * leftNode = oldRoot->left;
    Node * subTree = leftNode->right;

    leftNode->right = oldRoot;
    oldRoot->left = subTree;
    *root = leftNode;
}

void leftRightRotation(Node ** root) {
    leftRotation(&((*root)->left));
    rightRotation(root);
}

void rightLeftRotation(Node ** root) {
    rightRotation(&((*root)->right));
    leftRotation(root);
}

void updateBST(Node ** root) {
    if(*root == NULL)
    return;
    int left = (*root)->left ? (*root)->left->height : -1;
    int right = (*root)->right ? (*root)->right->height : -1;
    int balance = left - right;
    
    if(balance > 1) {
        int childBal = ((*root)->left->left ? (*root)->left->left->height : -1) -
                       ((*root)->left->right ? (*root)->left->right->height : -1);
        if(childBal >= 0)
            rightRotation(root);
        else
            leftRightRotation(root);
    }
    else if(balance < -1) {
        int childBal = ((*root)->right->left ? (*root)->right->left->height : -1) -
                       ((*root)->right->right ? (*root)->right->right->height : -1);

        if(childBal <= 0)
            leftRotation(root);
        else
            rightLeftRotation(root);
    }

    updateBST(&((*root)->left));
    updateBST(&((*root)->right));
    (*root)->height = updateNodeHeight(*root);
}

void display(Node * root) {
    if(root == NULL) {
        return;
    }
    printf("value: %d | height: %d\n", root->data, root->height);
    display(root->left);
    display(root->right);
}

Node * delete(Node * root, int value) {
    if(root == NULL)
        return NULL;
    
    if(value < root->data) {
        root->left = delete(root->left, value);
        root->height = updateNodeHeight(root);
        return root;
    }
    else if(value > root->data) {
        root->right = delete(root->right, value);
        root->height = updateNodeHeight(root);
        return root;
    }
    else if(root->data == value) {
        printf("Target Found!\n");
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if(root->left == NULL) {
            root->data = root->right->data;
            free(root->right);
            root->height = updateNodeHeight(root);
            return root;
        }
        else if(root->right == NULL) {
            root->data = root->left->data;
            free(root->left);
            root->height = updateNodeHeight(root);
            return root;
        }
        else {
            int data = findMax(root->left);
            root->data = data;
            root->left = delete(root->left, data);
            root->height = updateNodeHeight(root);
            return root;
        }
    }
}


int main() {
    Node * root = NULL;
    int values[] = {9, 7, 13, 4, 11, 10};
    int nodesTotal = sizeof(values) / sizeof(values[0]);
    int i;

    root = insert(root, values[0]);
    for(i = 1; i < nodesTotal; i++) {
        insert(root, values[i]);
    }

    display(root);
    
    printf("tree height: %d.\n", updateNodeHeight(root));
    printf("is avl tree? %s.\n", (isAVLTree(root) ? "true" : "false"));
    if(!isAVLTree(root)) {
        updateBST(&root);
        printf("Modified BST AVL:\n");
        display(root);
    }

    int target = 10;
    delete(root, target);
    nodesTotal--;
    printf("Successfully deleted node %d.\n", target);
    display(root);
    printf("is avl tree? %s.\n", (isAVLTree(root) ? "true" : "false"));
    if(!isAVLTree(root)) {
        updateBST(&root);
        printf("Modified BST AVL After deletion:\n");
        display(root);
    }


    return 0;
}