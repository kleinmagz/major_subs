#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * left;
    struct node * right;
} Node;
//prints in graphical form (chatGPT)
void printTree(Node *root, char *prefix, int isLeft) {
    if (root == NULL)
        return;

    printf("%s", prefix);

    // Print branch
    printf(isLeft ? "├── " : "└── ");

    // Print node
    printf("%d\n", root->data);

    // Prepare new prefix for children
    char newPrefix[100];
    sprintf(newPrefix, "%s%s", prefix, isLeft ? "│   " : "    ");

    // Left child (shown first)
    if (root->left || root->right) {
        printTree(root->left, newPrefix, 1);
        printTree(root->right, newPrefix, 0);
    }
}

void display( int ** x) {
    int * ptry = malloc(sizeof(int));
    *ptry = 10;
    printf(" display(): %p.\n", *x);
    *x = ptry;
}

int main() {
    int x = 5;
    int * ptrx = &x;
    printf("%p.\n", ptrx);
    display(&ptrx);
    printf("%d.\n", x);
    return 0;
}
