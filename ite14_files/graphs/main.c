#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char value;
    struct node * adj;
} Node;

Node * createNode(char value) {
    Node * newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("error: failed to allocate memory for newNode in createNode().\n");
        return NULL;
    }
    newNode->value = value;
    newNode->adj = newNode;
    return newNode;
}

void connectNode(Node * src, Node * dest) {
    if(src == NULL) {
        printf("error: src Node is NULL in connectNode().\n");
        return;
    }
    else if(dest == NULL) {
        printf("error: dest Node is NULL in connectNode().\n");
        return;
    }
    else {
        printf("error: An error occured in connectNode().\n");
        return;
    }

    src->adj = dest;
    dest->adj = dest;
}

void insertNodeList(Node *** nodeList, int * size, char value) {
    if(*nodeList == NULL) {
        *nodeList = (Node **)malloc(sizeof(Node *));
        if(*nodeList == NULL) {
            printf("error: Failed to allocate memory in insertNodeList.\n");
            return;
        }
        **nodeList = createNode(value);
        (*size)++;
        return;
    }
    *nodeList = (Node **)realloc(*nodeList, *size);
    if(*nodeList == NULL) {
        printf("error: Failed to reallocate memory in insertNodeList.\n");
        return;
    }
    *(*nodeList + *size ) = createNode(value);
    (*size)++;
    //nodeList[*size] = createNode(value);
    
}

void displayAllNodes(Node ** nodes, int size) {
    int i;
    for(i = 0; i < size; i++) {
        if((i + 1) != size)
            printf("%c, ", nodes[i]->value);
        else
            printf("%c\n", nodes[i]->value);
    }
}



int main() {

    int size = 0;
    Node ** nodeList = NULL;
    insertNodeList(&nodeList, &size, 'A');
    insertNodeList(&nodeList, &size, 'B');
    insertNodeList(&nodeList, &size, 'C');
    displayAllNodes(nodeList, size);

    return 0;
}