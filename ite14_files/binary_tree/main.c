#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;
    struct node * leftChild;
    struct node * rightChild;
} Node;

Node * createNode()
{
    Node * newNode = ( Node * )malloc( sizeof( Node ) );
    if( newNode == NULL )
    {
        return NULL;
    }
    return newNode;
}

void promptUser( Node ** node )
{
    int xx;
    printf( "Enter value: " );
    scanf( "%d", &xx );

    ( *node )->x = xx;

}

Node * createTree(int currlevel, int level )
{
    Node * newNode = createNode();

    if( level == 0 )
    {
        promptUser( &newNode );
        return newNode;
    }

    if( currlevel > level ){
        free( newNode );
        return NULL;
    }
    promptUser( &newNode );
    printf( "node: %d level %d created.\n", newNode->x, currlevel );
    newNode->leftChild = createTree( currlevel + 1, level );
    newNode->rightChild = createTree( currlevel + 1, level);
    return newNode;
}

void makeTree( Node ** root )
{
    int levels;
    
    printf( "Enter levels: " );
    scanf( "%d", &levels );

    *root = createTree( 0, levels );
}

void display( Node * node )
{
    if( node == NULL )
    {
        return;
    }
    printf( "%d, ", node->x );
    display( node->leftChild );
    display( node->rightChild );
}

int main()
{
    Node * root = NULL;
    int running = 1;
    int ch;

    while( running )
    {
        printf( "\n[1]Create Tree\n[2]Display\n[3]Exit\n" );
        printf( "Enter choice: " );
        scanf( "%d", &ch );

        switch( ch )
        {
            case 1:
                makeTree( &root );
                break;
            case 2:
                display( root );
                break;
            case 3:
                running = 0;
                break;
        }
    }

    return 0;
}