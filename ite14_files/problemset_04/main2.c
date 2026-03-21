#include <stdio.h>
#include <stdlib.h>

typedef struct nodes {
    int x;
    struct nodes * prev;
} Node;

// Create a function that returns a created node
Node * createNode( int x )
{
    Node * newNode = ( Node * )malloc( sizeof( Node ) );
    if( newNode == NULL )
        return NULL;
    newNode->x = x;
    newNode->prev = NULL;
    return newNode;
}

void push( Node ** top, Node * newNode )
{
    newNode->prev = *top;
    *top = newNode;
}

void printNodes( Node * curr )
{
    while( curr != NULL )
    {
        printf( "%d -> ", curr->x );
        curr = curr->prev;
    }
    printf( "\n" );
}

void pop( Node ** top )
{
    Node * toDelete = *top;
    *top = (*top)->prev;
    free( toDelete );
}

int main()
{
    Node * n1 = NULL;
    Node * top = NULL;
    n1 = ( Node * )malloc( sizeof( Node ) );
    n1->x = 10;
    n1->prev = NULL;

    Node * head = NULL;
    head = n1;
    top = head;

    // Create n2 where x = 15 and add in the stack
    Node * n2 = ( Node * )malloc( sizeof( Node ) );
    n2->x = 15;
    n2->prev = top;
    top = n2;

    // Create n3 where x = 20 and add in the stack
    Node * n3 = createNode( 20 );
    n3->prev = top;
    top = n3;
   

    // Create n4 where x = 30
    // call createNode( int x )
    // Then create a function push(...) to add the created Node
    // to the stack
    Node * n4 = createNode( 30 );
    push( &top, n4 );

    printNodes( top );

    pop( &top );
    printNodes( top );
    return 0;
}