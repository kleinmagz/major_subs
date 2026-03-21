#include <stdio.h>
#include <stdlib.h>

struct nodes
{
    int x;
    struct nodes *leftNode;
    struct nodes *rightNode;
};

int main(){
    struct nodes *n1, *n2, *n3;

    n1 = (struct nodes *) malloc (sizeof(struct nodes));
    n1->x = 10;
    n1->leftNode = NULL;
    n1->rightNode = NULL;

    n2 = (struct nodes *) malloc (sizeof(struct nodes));
    n2->x = 20;
    n2->leftNode = NULL;
    n2->rightNode = NULL;

    n3 = (struct nodes *) malloc (sizeof(struct nodes));
    n3->x = 30;
    n3->leftNode = NULL;
    n3->rightNode = NULL;

    //connect the nodes n1 -> n2 -> n3
    n1->rightNode = n2;
    ////////////////////
    n2->leftNode = n1;
    n2->rightNode = n3;
    ////////////////////
    n3->leftNode = n2;
    ////////////////////


    //Initialize Head and current and
    //display the nodes X
    struct nodes *head, *current;
    head = n1;
    current = head;
    printf("\n1st List\n");
    while(current != NULL){
        printf("%d ", current->x);
        current = current->rightNode;
    }
    /////////////////////////////////

    //create new node n4
    struct nodes *n4;
    n4 = (struct nodes *) malloc (sizeof(struct nodes));
    n4->x = 5;
    n4->leftNode = NULL;
    n4->rightNode = NULL;

    //add new node (n4) at the biginning of the list
    n4->rightNode = head;
    head->leftNode = n4;
    head = n4;

    //display again the nodes X
    printf("\n2nd List\n");
    current = head;
    while(current != NULL){
        printf("%d ", current->x);
        current = current->rightNode;
    }
    /////////////////////////////////

    //create new node n5
    struct nodes *n5;
    n5 = (struct nodes *) malloc (sizeof(struct nodes));
    n5->x = 50;
    n5->leftNode = NULL;
    n5->rightNode = NULL;

    //add new node (n5) at the end of the list
    current = head;
    while(current != NULL){
        if(current->rightNode == NULL){
            current->rightNode = n5;
            n5->leftNode = current;
            break;
        }
        current = current->rightNode;
    }


    //display again the nodes X
    printf("\n3rd List\n");
    current = head;
    while(current != NULL){
        printf("%d ", current->x);
        current = current->rightNode;
    }
    /////////////////////////////////

    //delete the first node where value of 20
    current = head;
    while(current != NULL){
        if(current->x == 20){
            //check if the node is the 1st element
            if(current->leftNode == NULL){
                head = current->rightNode;
                head->leftNode = NULL;
                free(current);
                current = NULL;
            }
            //check if the node is the last element
            else if(current->rightNode == NULL){
                current->leftNode->rightNode = NULL;
                free(current);
                current = NULL;
            //else if in the middle of two nodes
            }else {
                current->leftNode->rightNode = current->rightNode;
                current->rightNode->leftNode = current->leftNode;
            }
            break;
        }
        current = current->rightNode;
    }

    //display again the nodes X
    printf("\n4th List\n");
    current = head;
    while(current != NULL){
        printf("%d ", current->x);
        current = current->rightNode;
    }
    /////////////////////////////////

    return 0;
}
