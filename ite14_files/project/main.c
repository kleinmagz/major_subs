// compile this using this command: gcc main.c -lm
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CHECK "\xE2\x9C\x93"
#define WRONG "\xE2\x9C\x97"

// clears screen
void clearScr() {
    printf( "\033[H\033[2J" );
}

void clearStdIn() {
    // Source - https://stackoverflow.com/a/7898516
    // Posted by jamesdlin, modified by community. See post 'Timeline' for change history
    // Retrieved 2026-05-05, License - CC BY-SA 4.0

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

typedef struct Node {
    int data;
    int level;
    struct Node * left;
    struct Node * right;
} Node;

typedef struct QueueNode {
    Node * node;
    struct QueueNode * next;
} QueueNode;

// For level order traversal any other queue operations
QueueNode * queue = NULL;
Node * node = NULL;

// For level order traversal
QueueNode * createQueueNode(Node * node) {
    QueueNode * new = (QueueNode *)malloc(sizeof(QueueNode));
    if(new == NULL)
        return NULL;
    new->node = node;
    new->next = NULL;
}

Node * createNode(int data) {
    Node * newNode = (Node *)malloc(sizeof(Node));
    if(newNode == NULL)
        return NULL;
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// For level order traversal
void enqueue(QueueNode ** front, Node * node) {
    if(node == NULL) {
        return;
    }
    QueueNode * newNode = createQueueNode(node);
    if(*front == NULL) {
        *front = newNode;
        return;
    }
    QueueNode * curr = *front;

    while(curr->next != NULL)
        curr = curr->next;
    
    curr->next = newNode;
}

// For level order traversal
Node * dequeue(QueueNode ** front) {
    if(*front == NULL) return NULL;
    
    QueueNode * toDelete = *front;
    Node * returnNode = toDelete->node;
    *front = toDelete->next;
    free(toDelete);
    return returnNode;
}


Node * insertNode(Node * root, int data, int level) {
    if(root == NULL){
        Node * newNode = createNode(data);
        newNode->level = level;
        return newNode;
    }
    root->level = level;
    if(data < root->data) {
        root->left = insertNode(root->left, data, level + 1);
    }
    else if(data > root->data) {
        root->right = insertNode(root->right, data, level + 1);
    }
    return root;
}


int getHeight(Node * root) {
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return root->level;
    
    int left = getHeight(root->left);
    int right = getHeight(root->right);

    if(left > right)
        return left;
    else
        return right;
}

void addNode(Node ** root, int * nodeCount) {
    int numberOfNodes, data;
    int i;
    int failedInserts = 0;

    clearScr();
    printf("< ADD NODES >\n\n");
    printf("Enter how many nodes to insert: ");
    scanf("%d", &numberOfNodes);

    for(i = 0; i < numberOfNodes; i++) {
        printf("Enter number: ");
        if(scanf("%d", &data)) {
            if(*root == NULL) {
                *root = insertNode(*root, data, 0);
                continue;
            }
            insertNode(*root, data, 0);
        }
        else {
            failedInserts++;
            continue;
        }
    }
    *nodeCount += numberOfNodes;
}

void displayTree(Node * root) {
    if(root == NULL )
        return;
    printf("data: %d | level: %d\n", root->data, root->level);
    displayTree(root->left);
    displayTree(root->right);
}



void inorder(Node * root) {
    if(root == NULL)
        return;

    inorder(root->left);
    printf("[ %d ]", root->data);
    inorder(root->right);
}

void preorder(Node * root) {
    if(root == NULL)
        return;
    printf("[ %d ]", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node * root) {
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("[ %d ]", root->data);
}

void levelOrder(Node * root, int nodeCount) {
    int * visitedNodes = (int *)calloc(nodeCount, sizeof(int));
    int i = 0; int j = 0;
    enqueue(&queue, root);
    while(queue != NULL) {
        node = dequeue(&queue);
        if(node == NULL)
            continue;
        visitedNodes[i] = node->data;
        enqueue(&queue, node->left);
        enqueue(&queue, node->right);
        i++;
    }
    
    for(; j < nodeCount; j++)
        printf("[ %d ]", visitedNodes[j]);
    free(visitedNodes);
}


void traversalSubMenu(Node * root, int nodeCount) {
    int choice;
    int isRunning = 1;
    while(isRunning) {
        clearScr();
        printf("< TRAVERSAL OPTIONS >\n\n");
        printf("[1] Inorder Traversal\n[2] Preorder Traversal\n[3] Postorder Traversal\n[4] Level Order Traversal\n[5] Back to Main Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(root == NULL && choice != 5) {
            clearScr();
            clearStdIn();
            printf("< TRAVERSAL OPTIONS >\n\n");
            printf("There is no tree to traverse.\n");
            printf("\n[press any key to continue].\n");
            getchar();
            continue;
        }

        switch(choice) {
            case 1:
                clearScr();
                clearStdIn();
                printf("< INORDER TRANSVERSAL >\n\n");
                inorder(root);
                printf("\n[press any key to continue].\n");
                getchar();
                break;
            case 2:
                clearScr();
                clearStdIn();
                printf("< PREORDER TRANSVERSAL >\n\n");
                preorder(root);
                printf("\n[press any key to continue].\n");
                getchar();
                break;
            case 3:
                clearScr();
                clearStdIn();
                printf("< POSTORDER TRANSVERSAL >\n\n");
                postorder(root);
                printf("\n[press any key to continue].\n");
                getchar();
                break;
            case 4:
                clearScr();
                clearStdIn();
                printf("<LEVEL ORDER TRANSVERSAL>\n\n");
                levelOrder(root, nodeCount);
                printf("\n[press any key to continue].\n");
                getchar();
                break;
            case 5:
                isRunning = 0;
                break;
            default:
                printf("Invalid Input.\n");
        }
    }
}

int search(Node * root, int target) {
    if(root == NULL) 
        return 0;
    
    if(root->data == target)
        return 1;
    
    if(target > root->data) {
        return 1 && search(root->right, target);
    }
    else if(target < root->data) {
        return 1 && search(root->left, target);
    }
}

void searchValue(Node * root) {
    int value;
    clearScr();
    printf("< SEARCH VALUE >\n\n");
    if(root == NULL) {
        printf("There is no tree.\n");
    }
    else {
        printf("Enter value: ");
        scanf("%d", &value);
        printf("%d %s\n", value, (search(root, value)) ? "exists in the tree" : "does not exist in the tree");
    }
    clearStdIn();
    printf("\n\n[press any key to continue]\n");
    getchar();
}
// nodes have 2 or 0 children
int isStrictBST(Node * root) {
    enqueue(&queue, root);
    while(queue != NULL) {
        node = dequeue(&queue);
        if(node->left == NULL && node->right == NULL)
            continue;
        if(node->left == NULL || node->right == NULL) {
            // dequeue any remaining QueueuNodes
            while(queue != NULL) dequeue(&queue);
            return 0;
        }
        enqueue(&queue, node->left);
        enqueue(&queue, node->right);
    }
    // dequeue any remaining QueueuNodes
    while(queue != NULL) dequeue(&queue);
    return 1;
} 
//every level is filled except possibly at the last level (must be left filled)
int isCompleteBST(Node* root) {
    if (root == NULL) return 1;

    int foundNull = 0;
    enqueue(&queue, root);

    while (queue != NULL) {
        Node* node = dequeue(&queue);

        if (node->left != NULL) {
            if (foundNull) { 
                // dequeue any basta Hahhahaha
                while (queue != NULL) dequeue(&queue); 
                return 0; 
            }
            enqueue(&queue, node->left);
        } else {
            foundNull = 1;
        }

        if (node->right != NULL) {
            if (foundNull) { 
                // dequeue any remaining nodes in queue
                while (queue != NULL) dequeue(&queue); 
                return 0; 
            }
            enqueue(&queue, node->right);
        } else {
            foundNull = 1;
        }
    }
    return 1;
}

int countNodes(Node* root) {
    if (root == NULL) 
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int isPerfectBST(Node* root, int height) {
    int expectedNodes = (int)pow(2, height + 1) - 1;
    int actualNodes = countNodes(root);
    return actualNodes == expectedNodes;
}


void treeType(Node * root, int height) {
    clearScr();
    printf("< TREE TYPE >\n\n");

    if(root) {
        printf("strict binary tree: \t\t%s\n", isStrictBST(root) ? CHECK : WRONG);
        printf("complete binary tree: \t\t%s\n", isCompleteBST(root) ? CHECK : WRONG); 
        printf("full binary tree: \t\t%s\n", isFullBST(root, height) ? CHECK : WRONG);
    }
    else {
        printf("There is no tree.\n");
    }
    clearStdIn();
    printf("\n[press any key to continue]\n");
    getchar();
}

void printLeaves(Node * root) {
    if(root == NULL)
        return;
    if(root->left == NULL && root->right == NULL) {
        printf("[ %d ]", root->data);
        return;
    }
    printLeaves(root->left);
    printLeaves(root->right);
}

void displayLeaves(Node * root) {
    clearScr();
    printf("< DISPLAY LEAVES >\n\n");
    if(root == NULL)
        printf("There is no tree.\n");
    else
        printLeaves(root);
    printf("\n\n[press any key to continue]\n");
    clearStdIn();
    getchar();
}

Node * getParent(Node * root, int target) {
    if(root == NULL)
        return NULL;
    if(root->data == target)
        return NULL;
    while(1) {
        if(root->left == NULL && root->right == NULL)
            return NULL;
        if(root->left != NULL) {
            if(root->left->data == target)
                return root;
        }
        if(root->right != NULL) {
            if(root->right->data == target)
                return root;
        }
        if(target > root->data)
            root = root->right;
        else if(target < root->data)
            root = root->left;
    }
}


void displaySiblings(Node * root) {
    clearScr();
    printf("< DISPLAY SIBLINGS >\n\n");
    if(root == NULL) {
        printf("There is no tree.\n");
        clearStdIn();
        printf("\n[press any key to continue]\n");
        getchar();
        return;
    }
    int target;
    int isFound;
    Node * parent = NULL;
    printf("Enter value: ");
    scanf("%d", &target);
    if(!search(root, target)) {
        printf("%d does not exist in the tree.\n", target);
        clearStdIn();
        printf("\n[press any key to continue]\n");
        getchar();
        return;
    }
    parent = getParent(root, target);
    if(parent == NULL) {
        printf("Parent =>\tNULL\n");
        printf("Target =>\tdata : %d | level : %d\n", target, 0);
        printf("[No Siblings]\n");
    }
    else {
        printf("Parent =>\tdata : %d | level : %d\n", parent->data, parent->level);
        printf("Target =>\tdata : %d | level : %d\n", target, (parent->level) + 1);
        if(parent->left != NULL && parent->right != NULL) 
            printf("Sibling =>\tdata : %d | level : %d\n", (parent->left->data != target) ? parent->left->data : parent->right->data, (parent->level) + 1);
        else
            printf("[No Siblings]\n");
    }
    clearStdIn();
    printf("\n[press any key to continue]\n");
    getchar();
}

void displayMenu(Node ** root) {
    int choice;
    int isRunning = 1;
    int nodeCount = 0;
    int treeHeight = 0;

    while(isRunning) {
        clearScr();
        //displayTree(*root);
        printf("< MAIN MENU >\n\n");
        printf("[1] Traversal Operations\n[2] Add Nodes\n[3] Search Value\n[4] Determine Tree Type\n[5] Display Leaves\n[6] Display Siblings\n[7] Exit\n");
        printf("Enter Option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                traversalSubMenu(*root, nodeCount);
                break;
            case 2:
                addNode(&(*root), &nodeCount);
                break;
            case 3:
                searchValue(*root);
                break;
            case 4:
                treeType(*root, treeHeight);
                break;
            case 5:
                displayLeaves(*root);
                break;
            case 6:
                displaySiblings(*root);
                break;  
            case 7:
                isRunning = 0;
                break;
            case 8:
                printf("%d", getHeight(*root));
                clearStdIn();
                getchar();
                break;
            default:
                printf("Invalid input.\n");
        }
        treeHeight = getHeight(*root);
    }
}


int main() {
    Node * root = NULL;
    displayMenu(&root);
    clearScr();
    printf("Bye.\n"); 
    return 0;
}