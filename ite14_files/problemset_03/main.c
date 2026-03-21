#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NEXTLINES "\n\n"
#define PRINT_BOOL(x) (x) ? "true" : "false"
#define PRESS_ANY_KEY "[Press any key to continue]\n"

const int MAX_STACK_SIZE = 10;

typedef struct node
{
    int x;
    struct node * next;
} Node;

void clearScr()
{
    printf( "\033[H\033[2J" );
}

void clearBuff()
{
    char c;
    while( ( c = getchar() ) != '\n' && c == EOF );
}


Node * creatNode()
{
    Node * newNode = ( Node * )malloc( sizeof( Node ) );
    if( newNode == NULL )
        return NULL;
    
    clearScr();
    printf( NEXTLINES );
    printf( "Enter x: " );
    scanf( "%d", &newNode->x );
    newNode->next = NULL;

    return newNode;
}


bool isEmpty( Node * stack )
{
    return stack == NULL;
}

bool isFull( int count )
{
    return count == MAX_STACK_SIZE;
}

void push( Node ** stackHead, Node **top, int * nodeCount )
{
    Node * newNode = NULL;

    if( isEmpty( *stackHead ) )
    {
        newNode = creatNode();
        if( newNode == NULL )
        {
            printf( "Failed to create Node.\n" );
            return;
        }

        *stackHead = newNode;
        *top = newNode;
        ( *nodeCount )++;
        return;
    }

    if( isFull( *nodeCount ) )
    {
        clearScr();
        clearBuff();
        printf( NEXTLINES );
        printf( "The stack is full.\n\n%s", PRESS_ANY_KEY );
        getchar();
        return;
    }

    newNode = creatNode();
    if( newNode == NULL )
    {
        printf( "Failed to create Node.\n" );
        return;
    }

    ( *top )->next = newNode;
    ( *top ) = newNode;
    ( *top )->next = NULL;
    ( *nodeCount )++;
}

void pop( Node ** stackHead, Node ** top, int * nodeCount )
{
    if( isEmpty( *stackHead ) )
    {
        return;
    }

    Node * toDelete = NULL;
    Node * topPrev = *stackHead;

    if( *nodeCount == 1 )
    {
        toDelete = *stackHead;
        free( toDelete );
        *top = NULL;
        *stackHead = NULL;
        ( *nodeCount )--;
        return;
    }

    toDelete = *top;
    while( topPrev->next != toDelete )
        topPrev = topPrev->next;
    free( toDelete );
    *top = topPrev;
    ( *top )->next = NULL;
    ( *nodeCount )--;

}

void topFunction( Node * top )
{
    clearScr();
    clearBuff();
    printf( NEXTLINES );
    if( top == NULL )
    {
        printf( "The stack is empty.\n\n%s", PRESS_ANY_KEY );
        getchar();
        return;
    }

    printf( "Top stack pointer value: %d\n\n%s", top->x, PRESS_ANY_KEY );
    getchar();
}

void size( int nodeCount )
{
    clearBuff();
    clearScr();
    printf( NEXTLINES );

    if( nodeCount == 0 )
    {
        printf( "The stack is empty.\n\n%s", PRESS_ANY_KEY );
        getchar();
        return;
    }

    printf( "Stack size: %d\n\n%s", nodeCount, PRESS_ANY_KEY );
    getchar();
}

void displayStackStatus( Node * stackHead, int nodeCount, int ch )
{
    clearBuff();
    clearScr();
    printf( NEXTLINES );

    if( isEmpty( stackHead ) && nodeCount == 0 && ch == 5 )
    {
        printf( "Empty stack:\t%s\n\n%s\n", PRINT_BOOL( isEmpty( stackHead ) ), PRESS_ANY_KEY );
        getchar();
    }
    else if( !isEmpty( stackHead ) && nodeCount > 0 && ch == 5 )
    {
        printf( "Empty stack:\t%s\n\n%s\n", PRINT_BOOL( isEmpty( stackHead ) ), PRESS_ANY_KEY );
        getchar();
    }
    else if( isFull( nodeCount ) && ch == 6 )
    {
        printf( "Full stack:\t%s\n\n%s\n", PRINT_BOOL( isFull( nodeCount ) ), PRESS_ANY_KEY );
        getchar();
    }
    else if( !isFull( nodeCount ) && ch == 6 )
    {
        printf( "Full stack:\t%s\nRemaining:\t%d\n\n%s\n", PRINT_BOOL( isFull( nodeCount ) ), MAX_STACK_SIZE - nodeCount, PRESS_ANY_KEY );
        getchar();
    }
}

void display( Node * stackHead )
{
    Node * curr = stackHead;

    if( stackHead == NULL )
    {
        printf( "[EMPTY]\n" );
        return;
    }

    while( curr != NULL )
    {
        if( curr->next == NULL )
        {
            printf( "%d \n", curr->x );
            curr = curr->next;
            continue;
        }

        printf( "%d -> ", curr->x );
        curr = curr->next;
    }

}

int main()
{
    Node * stackHead = NULL;
    Node * top = NULL;

    bool isRunning = true;
    int ch;
    int nodeCount = 0;


    while( isRunning )
    {
        clearScr();
        printf( NEXTLINES );
        display( stackHead );
        printf( "[1]Push\n[2]Pop\n[3]Top\n[4]Size\n[5]Is Empty\n[6]Is Full\n[7]Exit\n\n" );
        printf( "Enter option: " );
        scanf( "%d", &ch );
        
        switch( ch )
        {
            case 1:
                push( &stackHead, &top, &nodeCount );
                break;
            case 2:
                pop( &stackHead, &top, &nodeCount );
                break;
            case 3:
                topFunction( top );
                break;
            case 4:
                size( nodeCount );
                break;
            case 5:
                displayStackStatus( stackHead, nodeCount, ch );
                break;
            case 6:
                displayStackStatus( stackHead, nodeCount, ch );
                break;
            case 7:
                isRunning = false;
                break;
        }
    }
    return 0;
}