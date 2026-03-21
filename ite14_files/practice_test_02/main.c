#include <stdio.h>
#include <stdlib.h>
#define NEXT_LINES "\n"

typedef struct node{
    int x;
    struct node * prev;
    struct node * next;
} Node;

// Clears the screen
void clearScr()
{
    printf( "\033[H\033[2J" );
}

void clearBuff()
{
    char c;
    while( ( c = getchar() ) != '\n' && c == EOF );
}

// Helper function
Node * createNode( int * count )
{
    Node * newNode = ( Node * )malloc( sizeof( Node ) );
    if( newNode == NULL )
    {
        return NULL;
    }
    clearScr();
    printf( NEXT_LINES "Enter x: " );
    scanf( "%d", &( newNode )->x );
    newNode->next = NULL;
    newNode->prev = NULL;
    ( *count )++;
    return newNode;
}

// Helper function - delete a specific node
void deleteNode( Node * node, int * count )
{
    if( node == NULL )
    {
        return;
    }
    
    ( *count )--;
    free( node );
}

// Helper function - if head is still NULL
void init_head( Node ** head, int * count )
{
    clearScr();
    printf( NEXT_LINES );
    *head = createNode( &( *count ) );
}

// Helper function; free all nodes upon exiting the program
void freeNodes( Node ** head )
{
    if ( *head == NULL )
    {
        return;
    }

    Node * curr = *head;
    // Modes to the last node of the list
    while( curr->next != NULL )
    {
        curr = curr->next;
    }

    while( curr->prev != NULL )
    {
        curr = curr->prev;
        free( curr->next );
    }

    free( curr );
}


void addNode_start( Node ** head, int * count )
{
    Node * curr = NULL;
    Node * newNode = NULL;
    if( *head == NULL )
    {
        init_head( &( *head ), &( *count ) );
        return;
    }

    
    newNode = createNode( &( *count ) );
    curr = *head;

    newNode->next = curr;
    curr->prev = newNode;

    *head = newNode;
}

void addNode_middle( Node ** head, int * count )
{
    if( *head == NULL )
    {
        init_head( &( *head ), &( *count ) );
        return;
    }
    Node * curr = NULL;
    Node * newNode = NULL;
    int i = 0;
    int target_i = ( *count ) / 2; // middle 


    curr = *head;

    if( curr->next == NULL )
    {
        newNode = createNode( &( *count ) );
        curr->next = newNode;
        newNode->prev = curr;
        return;
    }
    
    while( curr != NULL )
    {
        // if is in target and node count is even
        if( i == target_i && ( (*count % 2) == 0 ) )
        {
            newNode = createNode( &( *count ) );
            curr->prev->next = newNode;
            newNode->prev = curr->prev;
            newNode->next = curr;
            curr->prev = newNode;
            return;
        }
         
        // otherwise basta gets mo na
        if( i == target_i && ( (*count % 2) != 0 ) )
        {
            newNode = createNode( &( *count ) );
            curr->next->prev = newNode;
            newNode->next = curr->next;
            newNode->prev = curr;
            curr->next = newNode;
            return;
        }

        curr = curr->next;
        i++;
    }
}

void addNode_end( Node ** head, int * count )
{
    if( *head == NULL )
    {
        init_head( &( *head ), &( *count ) );
        return;
    }

    Node * curr = *head;
    Node * newNode = NULL;

    while( curr->next != NULL )
    {
        curr = curr->next;
    }

    newNode = createNode( &( *count ) );
    newNode->prev = curr;
    curr->next = newNode;    

}

void deleteNode_start( Node ** head, int * count )
{
    if( *head == NULL )
    {
        return;
    }
    Node * toDelete = NULL;
    Node * curr = NULL;

    toDelete = *head;
    curr = *head;

    if( curr->next == NULL )
    {
        deleteNode( toDelete, &( *count ) );
        *head = NULL;
        return;
    }

    curr->next->prev = NULL;
    *head = curr->next;

    deleteNode( toDelete, &( *count ) );
}

void deleteNode_middle( Node ** head, int * count )
{
    if( *head == NULL )
    {
        return;
    }
    Node * toDelete = NULL;
    Node * curr = NULL;
    int i = 0;
    int target_i = ( *count ) / 2;

    curr = *head;
    
    if( curr->next == NULL )
    {
        deleteNode( *head, &( *count ) );
        *head = NULL;
        return;
    }

    if( *count == 2 )
    {
        deleteNode( curr->next, &( *count ) );
        curr->next = NULL;
        return;
    }

    while( curr != NULL )
    {
        if( i == target_i )
        {
            toDelete = curr;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            deleteNode( toDelete, &( *count ) );
            return;
        }
        i++;
        curr= curr->next;
    }
}

void deleteNode_end( Node ** head, int * count )
{
    if( *head == NULL )
    {
        return;
    }

    Node * toDelete = NULL;
    Node * curr = NULL;

    curr = *head;

    if( curr->next == NULL )
    {
        deleteNode( *head, &( *count ) );
        *head = NULL;
        return;
    }

    while( curr->next != NULL )
    {
        curr = curr->next;
    }

    toDelete = curr;
    curr->prev->next = NULL;
    deleteNode( toDelete, &( *count ) );
}

void display_start( Node * curr )
{
    if( curr == NULL )
    {
        return;
    }

    clearScr();
    printf( NEXT_LINES );
    while( curr != NULL )
    {
        if( curr->next == NULL )
        {
            printf( "%d", curr->x );
            curr = curr->next;
            continue;
        }

        printf( "%d -> ", curr->x );
        curr = curr->next;
    }

    clearBuff();
    printf( "\nEnter any key to continue.\n" );
    getchar();
}

void display_end( Node * curr )
{
    if( curr == NULL )
    {
        return;
    }
    clearScr();
    printf( NEXT_LINES );
    while( curr->next != NULL )
    {
        curr = curr->next;
    }

    while( curr != NULL )
    {
        if( curr->next == NULL )
        {
            printf( "%d", curr->x );
            curr = curr->prev;
            continue;
        }

        printf( " -> %d", curr->x );
        curr = curr->prev;
    }
    clearBuff();
    printf( "\nEnter any key to continue.\n" );
    getchar();
}

// Comment this out when deployinh: for debugging purposes
// only
//void display( Node * curr, int count )
//{
//    if( curr == NULL )
//    {
//        printf( "[NULL]\n" );
//        printf( "Count: %d\n\n", count );
//        return;
//    }
//    while( curr != NULL )
//    {
//        printf( "%d -> ", curr->x );
//        curr = curr->next;
//    }
//    printf( "\nCount: %d\n\n", count );
//}

int main()
{
    Node * head = NULL;
    int ch, running = 1; int count = 0;

    while( running )
    {
        clearScr();
        printf( NEXT_LINES );
        //display( head, count );
        printf( "[1]Add a node at the beginning\n" );
        printf( "[2]Add a node in the middle\n" );
        printf( "[3]Add a node at the end\n" );
        printf( "[4]Delete the node at the beginning\n" );
        printf( "[5]Delete a node from the middle\n" );
        printf( "[6]Delete the node at the end\n" );
        printf( "[7]Display all nodes from start to end\n" );
        printf( "[8]Display all nodes from end to start\n" );
        printf( "[9]Exit\n\n" );
        printf( "Enter option: " );
        scanf( "%d", &ch );

        switch( ch )
        {
            case 1:
                addNode_start( &head, &count );
                break;
            case 2:
                addNode_middle( &head, &count );
                break;
            case 3:
                addNode_end( &head, &count );
                break;
            case 4:
                deleteNode_start( &head, &count );
                break;
            case 5:
                deleteNode_middle( &head, &count );
                break;
            case 6:
                deleteNode_end( &head, &count );
                break;
            case 7:
                display_start( head );
                break;
            case 8:
                display_end( head );
                break;
            case 9:
                running = 0;
                freeNodes( &head );
                break;
        }

    }
    return 0;
}
