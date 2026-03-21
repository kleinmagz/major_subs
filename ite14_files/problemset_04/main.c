#include <stdio.h>
#include <stdlib.h>

typedef struct nodes {
    int x;
    struct nodes * next;
} Node;

// Create a function that returns a created node
Node * createNode( int x )
{
    Node * newNode = ( Node * )malloc( sizeof( Node ) );
    if( newNode == NULL )
        return NULL;
    newNode->x = x;
    newNode->next = NULL;
    return newNode;
}

void push( Node * head, Node * newNode )
{
    if( newNode == NULL || head == NULL )
        return;
    Node * curr = head;
    while( curr->next != NULL )
        curr = curr->next;
    
    curr->next = newNode;
}

void printNodes( Node * curr )
{
    while( curr != NULL )
    {
        printf( "%d -> ", curr->x );
        curr = curr->next;
    }
    printf( "\n" );
}

int main()
{
    Node * n1 = NULL;
    n1 = ( Node * )malloc( sizeof( Node ) );
    n1->x = 10;
    n1->next = NULL;

    Node * head = NULL;
    head = n1;

    // Create n2 where x = 15 and add in the stack
    Node * n2 = ( Node * )malloc( sizeof( Node ) );
    n2->x = 15;
    n2->next = NULL;
    head->next = n2;

    // Create n3 where x = 20 and add in the stack
    Node * n3 = createNode( 20 );

    // Loop to the top
    Node * curr = head;
    while( curr->next != NULL )
        curr = curr->next;
    curr->next = n3;

    // Create n4 where x = 30
    // call createNode( int x )
    // Then create a function push(...) to add the created Node
    // to the stack
    Node * n4 = createNode( 30 );
    push( head, n4 );

    printNodes( head );
    return 0;
}