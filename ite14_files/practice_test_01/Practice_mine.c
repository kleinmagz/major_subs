#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int x;
    struct node * next;
}Node;

// For visual
void displayAllNodes( Node * curr )
{
    printf( "\n\n\n\n" );
    if( curr == NULL ){
        printf( "[There is nothing to display]\n" );
        return;
    }
    while( curr != NULL )
    {
        printf( "x: %d -> ", curr->x );
        curr = curr->next;
    }
    printf( "\n" );
}

Node * createNode()
{
    Node * newNode = ( Node * )malloc( sizeof( Node ) );
    if( newNode == NULL )
    {
        printf( "Allocation failed.\n" );
        exit( EXIT_FAILURE );
    }
    printf( "Enter x: " );
    scanf( "%d", &newNode->x );
    newNode->next = NULL;
    return newNode;

}

void addNode( Node ** head )
{
    if( *head == NULL ){
        *head = createNode();
        return;
    }

    Node * curr = *head;
    while( curr->next != NULL )
    {
        curr = curr->next;
    }
    curr->next = createNode();
}

void countNodes( Node * curr )
{
    int count = 0;
    while( curr != NULL )
    {
        count++;
        curr = curr->next;
    }
    printf( "There are %d nodes in the list.\n", count );
}

// Searches if Node has x == to user input
void search( Node * curr )
{
    if( curr == NULL )
    {
        printf( "There is nothing to search.\n " );
        return;
    }
    int target;
    printf( "Enter x: " );
    scanf( "%d", &target );
    
    while( curr != NULL )
    {
        if( curr->x == target )
        {
            printf( "Node with value: %d exists.\n", target );
            return;
        }

        curr = curr->next;
    }

    printf( "Node with value: %d does not exist.\n", target );
}

void displayEven( Node * curr )
{
    if( curr == NULL )
    {
        printf( "No nodes to display.\n" );
        return;
    }

    int index = 1;
    while( curr != NULL )
    {
        if( ( index % 2 ) == 0 )
        {
            printf( "Node %d; x: %d\n", index, curr->x );
        }
        index++;
        curr = curr->next;
    }
}

void deleteFirst( Node ** head )
{
    if( *head == NULL )
    {
        printf( "There is nothing to delete.\n" );
        return;
    }

    Node * curr = *head;
    *head = curr->next;
    free( curr );
}

void deleteLast( Node ** head )
{
    if( *head == NULL )
    {
        printf( "There is nothing to delete.\n" );
        return;
    }
    Node * curr = *head;

    if( curr->next == NULL )
    {
        free( *head );
        *head = NULL;
        return;
    }

    while( curr->next->next != NULL )
    {
        curr = curr->next;
    }
    free( curr->next );
    curr->next = NULL;
}

// Deletes the first instance of node with x == user input.
void deleteNode( Node ** head )
{
    if( *head == NULL )
    {
        printf( "There is nothing to delete.\n" );
        return;
    }
    int target;
    Node * curr = *head;

    printf( "Enter Node x to delete: " );
    scanf( "%d", &target );

    if( ( *head )->x == target )
    {
        Node * temp = *head;
        *head = temp->next;
        free( temp );
        return;
    }
    
    while( curr->next != NULL )
    {
        if( curr->next->x == target )
        {
            Node * temp = curr->next;
            curr->next = curr->next->next;
            free( temp );
            return;
        }
        curr = curr->next;
    }

    printf( "Node with x: %d does not exist.\n", target );
}

int main()
{
    Node * head = NULL;
    int running = 1;
    int choice;

    while( running )
    {
        displayAllNodes( head );
        printf( "[1]Add Node\n[2]Count List\n[3]Search\n[4]Display Even\n[5]Delete First Node\n[6]Delete Last Node\n[7]Delete a Node\n[8]Exit\n" );
        printf( "Enter choice: " );
        scanf( "%d", &choice );

        switch( choice )
        {
            case 1:
                addNode( &head );
                break;
            case 2:
                countNodes( head );
                break;
            case 3:
                search( head );
                break;
            case 4:
                displayEven( head );
                break;
            case 5:
                deleteFirst( &head );
                break;
            case 6:
                deleteLast( &head );
                break;
            case 7:
                deleteNode( &head );
                break;
            case 8:
                running = 0;
                break;
        }

    }

    return 0;
}