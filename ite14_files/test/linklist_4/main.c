// ************************************************
// HOW TO USE THIS PROGRAM
//
// [1] ADDING INTO A LINK LIST
//  When you press [1], you are adding a node into
//  the link list. This act similar to a stack where
//  each time you invoke this, you stack on top of the
//  previous node.
//
//  When invoked, you are then asked to input a value.
//
// [2] INSERTING INTO A LINK LIST
//  To insert a node in a link list, assuming a head is
//  already initialized, enter an index and then the node's
//  value. Entering an index will insert a new node after
//  that index.
//
//  For instance if index = 1, it will insert a new node 
//  between index 1 and 2. 
//  
//  index to insert = 1:  
//
//  *Initially:*
//  [index = 1] -> [ index = 2]
//  
//  *After Execution:*
//  [index = 1] -> [new node] -> [ index = 3(formerly 2)]
//
//  If you want to insert a new node before the head,
//  enter the value -1 to the target index. The new node
//  is now the new head.
//
// [3] DELETING A NODE
//  Operates similarly as inserting into a link list. The node
//  you input will delete the node after the index.
//
//  If you want to delete the current head of the list, enter
//  the value -1. The node after the former head will be the
//  new head.
//
// [4] SEEING YOUR LINK LIST (VISUALIZATION)
//  This displays the link list. It presents it from top to
//  to bottom where the top is the current head of the link
//  list.


#include <stdio.h>
#include <stdlib.h>

#define NEWLINES "\n\n\n\n"

const char FILENAME[] = "Nodes.txt";

typedef struct node{
    int id;
    int value;
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


// Used only once to initialize the head of the link list
void initHead( Node ** head , int * count, int * id )
{
    *head = ( Node * )malloc( sizeof( Node ) ) ;
    if ( ( *head ) == NULL )
    {
        perror( "E:\tMemory allocation failed at void initHead(Node **head, int *count)\n" );
        return;
    }

    clearScr();
    printf( NEWLINES "Enter value: " );
    scanf( "%d", &( *head )->value );
    clearBuff();

    ( *head )->id = ++( *id);
    ( *head )->next = NULL;
    ( *count )++;
    printf( "Head successfully added.\n" );
    getchar();
}

// After initialization of the head, to be used onwards.
// Adds on top of another node - like a stack.
void add( Node * curr, int * count, int * id )
{
    while ( curr->next != NULL )
    {
        curr = curr->next;
    }
    curr->next = ( Node * )malloc( sizeof( Node ) );
    if ( curr->next == NULL )
    {
        perror( "E:\tMemory allocation failed at void add( Node *curr, int *count).\n" );
        return;
    }


    clearScr();
    printf( NEWLINES "Enter value: " );
    scanf( "%d", &curr->next->value );
    clearBuff();

    curr->next->next = NULL;
    curr->next->id = ++( *id );
    ( *count )++;
    printf( "Node successfully added.\n" );
    getchar();
}

// insert after a indicated index
void insert( Node ** head, Node * curr, int * count, int * id )
{
    if( curr == NULL )
    {
        clearScr();
        printf( NEWLINES "E: Cannot insert without head of link list.\n" );
        getchar();
        return;
    }
    int i = 0;
    int index;
    Node * newNode = ( Node * )malloc( sizeof( Node ) );
    if ( newNode == NULL )
    {
        perror( "E:\tMemory allocation failed at void insert(Node *curr, int *count)" );
        return;
    }

    clearScr();
    printf( NEWLINES "Enter index to insert after: " );
    scanf( "%d", &index );
    clearBuff();

    
    if( index <= 0 )
    {
        printf( "Enter value: " );
        scanf( "%d", &newNode->value );
        clearBuff();
        newNode->id = ++( *id ); 
        newNode->next = *head;
        *head = newNode;
        printf( "Node successfully inserted.\n" );
        getchar();
        return;    
    }

    
    if( index > ( *count - 1 ) )
    {
        printf( "Enter value: " );
        scanf( "%d", &newNode->value );
        clearBuff();
        newNode->id = ++( *id );

        while( curr->next != NULL )
        {
            curr = curr->next;
        }

        curr->next = newNode;
        newNode->next = NULL;
        ( *count )++;
        printf( "Node successfully inserted.\n" );
        getchar();
        return;
    }
    
    printf( "Enter value: " );
    scanf( "%d", &newNode->value );
    clearBuff();
    newNode->id = ++( *id );
    
    while( 1 )
    {
        if( ( i + 1 ) == index )
        {
            break;
        }
        curr = curr->next;
        i++;
    }
    
    newNode->next = curr->next;
    curr->next = newNode;
    //curr = newNode;
    ( *count )++;
    printf( "Node successfully inserted.\n" );
    getchar();
}

// Deletes the node
void delete( Node ** head, Node * curr, int * count )
{
    if( curr == NULL )
    {   
        clearScr();
        printf( NEWLINES "E: Cannot delete without head of link list.\n" );
        getchar();
        return;
    }
    int i = 0;
    int index;
    Node * toDelete = NULL;


    clearScr();
    printf( NEWLINES "Enter index to delete: " );
    scanf( "%d", &index );
    clearBuff();

    if( index <= 0 )
    {
        toDelete = *head;
        *head = curr->next;
        free( toDelete );
        printf( "Index selected successfully deleted.\n" );
        getchar();
        return;
    }

    if( index >= ( *count - 1 ) )
    {
        while( curr->next->next != NULL )
        {
            curr = curr->next;
        }
        
        toDelete = curr->next;
        curr->next = NULL;
        free( toDelete );
        --( *count );
        printf( "Node successfully deleted.\n" );
        getchar();
        return;
    }

    while( 1 )
    {
        if ( i == index )
        {
            toDelete = curr->next;
            break;
        }
        curr = curr->next;
        i++;
    }
    curr->next = curr->next->next;
    free( toDelete );
    ( *count )--;
    printf( "Index selected successfully deleted.\n" );
    getchar();
}

// Prints all nodes in the linked list
void visualize( Node * curr )
{
    if( curr == NULL )
    {
        clearScr();
        printf( NEWLINES "There is nothing to display.\n" );
        getchar();
        return;
    }
    clearScr();
    printf( NEWLINES );
    while( curr != NULL )
    {
        printf( "====================\nNode.id:\t%d\nNode.value:\t%d\n====================\n", curr->id, curr->value );
        printf( "\t \u2193\n" );
        curr = curr->next;
    }
    getchar();
}

void loadNodes( Node ** head, int * id_out )
{
    int count = 0;
    int id; int value;
    Node * newNode = NULL;
    FILE * fptr = fopen( FILENAME, "r" );
    Node * curr = NULL;

    if( fptr == NULL )
    {
        clearScr();
        printf( NEWLINES "W: Unable to open file. Cannot load old data.\n" );
        getchar();
        //fclose( fptr );
        return;
    }

    while( fscanf( fptr, "%d %d", &id, &value ) == 2 )
    {
        newNode = ( Node * )malloc( sizeof( Node ) );
        if( newNode == NULL )
        {
            printf( "E: Cannot read input from file.\n" );
            free( newNode );
            continue;
        }
        newNode->id = id;
        newNode->value = value;

        if( *head == NULL )
        {
            *head = newNode;
            ( *head )->next = NULL;
            curr = *head;
            continue;
        }
        
        curr->next = newNode;
        curr = curr->next;
        curr->next = NULL;
    }
    *id_out = id;
    fclose( fptr );
}

void exportNodes( Node * curr )
{
    FILE * fptr = fopen( FILENAME, "w" );
    if( fptr == NULL )
    {
        clearScr();
        printf( "Unable to write into file.\n" );
        getchar();
        return;
    }
    if( curr == NULL )
    {
        clearScr();
        printf( NEWLINES "There is nothing to save.\n" );
        getchar();
        return;
    }
    while( curr != NULL )
    {
        fprintf( fptr, "%d %d\n", curr->id, curr->value );
        curr = curr->next;
    }
    fclose( fptr );
}

void menu()
{
    Node * head = NULL;
    int c, isQuit = 0; int nodeCount = 0;
    int id = 0;

    loadNodes( &head, &id );
    while( !isQuit )
    {
        clearScr();
        printf( NEWLINES "[1]Add\n[2]Insert\n[3]Delete\n[4]Visualize\n[5]Exit\n\n" );
        printf( "Enter option: " );
        scanf( "%d", &c );
        clearBuff();

        switch( c )
        {
            case 1:
                if( head == NULL )
                {
                    initHead( &head, &nodeCount, &id );
                    break;
                }

                add( head, &nodeCount, &id );
                break;
            case 2:
                insert( &head, head, &nodeCount, &id );
                break;
            case 3:
                delete( &head, head, &nodeCount);
                break;
            
            case 4:
                visualize( head );
                break;
            case 5: 
                isQuit = 1;
                break;
            default:
                clearScr();
                printf( NEWLINES "Invalid input.\n" );
                getchar();
        }
    }
    exportNodes( head );
}

int main()
{   
    menu();
    return 0;
}
