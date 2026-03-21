#include <stdio.h>
#include <stdlib.h>

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
    while( ( c = getchar() ) != '\n' && c != EOF );
}

void printValue( Node * curr, int count )
{
    clearScr();
    printf( "\n\n\n\nNode.id:\t%d\nNode:value:\t%d\n", curr->id, curr->value );
    printf( "Node count:\t%d\n", count );
    getchar();
}

void inputInitValues( Node *** head )
{
    clearScr();
    printf( "\n\n\n\nEnter value: " );
    scanf( "%d", &( **head )->value );
    clearBuff();
}

void inputValues( Node * curr, int ** count )
{
    clearScr();
    printf( "\n\n\n\nEnter value: " );
    scanf( "%d", &( curr )->value );
    clearBuff();

    curr->next = NULL;
    curr->id = ++( **count );
}

void initHead( Node ** head, int * count )
{
    *head = ( Node * )malloc( sizeof( Node ) );
    if( *head == NULL )
    {
        perror( "E:\tMemory allocation failed at void initHead( Node **head, int *count ).\n" );
        return;
    }

    inputInitValues( &head );
    ( *head )->id = ++( *count);
    ( *head )->next = NULL;
    printf( "Node.valule: %d\n", ( *head)->value );
}

void add( Node * curr, int * count )
{
    while ( curr->next != NULL )
    {
        curr = curr->next;
    }

    curr->next = ( Node * )malloc( sizeof( Node ) );
    if( curr->next == NULL )
    {
        perror( "E:\tMemory allocation failed at void add(Node *curr, int *count).\n" );
        return;
    }

    inputValues( curr->next, &( count ) );
}

void insert( Node * curr, int * count )
{
    int indexAfter, i = 0;
    Node * newNode = ( Node * )malloc( sizeof( Node ) );
    if( newNode == NULL )
    {
        perror( "E:\tMemory allocation failed at void insert(Node *curr, inr *count).\n" );
        return;
    }

    clearScr();
    printf( "\n\n\n\nEnter index to insert after: " );
    scanf( "%d", &indexAfter );

    if( indexAfter > ( *count ) - 1 )
    {
        printf( "Index entered exceeds the list.\n" );
        return;
    }

    while ( i != indexAfter && curr->next != NULL )
    {
        curr = curr->next;
        i++;
    }

    printf( "\n\n\n\nNode.id:\t%d\nNode:value:\t%d\n", curr->id, curr->value );
    clearScr();
    printf( "\n\n\n\nEnter Value: " );
    scanf( "%d", &newNode->value);
    newNode->id = ++( *count );
    newNode->next = curr;
    curr->next = newNode;
}

void searchByID( Node * curr, int count )
{
    int id;

    clearScr();
    printf( "\n\n\n\nEnter ID to search: " );
    scanf( "%d", &id );
    clearBuff();

    while( curr != NULL )
    {
        if( curr->id == id )
        {
            printValue( curr, count );
            return;
        }
        curr = curr->next;
    }
    printf( "Node does not exist\n");
    getchar();
}

void visualize( Node * curr, int count )
{
    int i = 0;
    while( i < count )
    {
        clearScr();
        printf( "\n\n\n\n=======\nID: %d\nValue: %d\n=======\n", curr->id, curr->value );
        curr = curr->next;
        i++;
    }
    getchar();
}

void menu()
{
    int isQuit = 0;
    int c, count = 0; int isFirst = 1;
    Node * head = NULL;

    while( !isQuit )
    {
        clearScr();
        printf( "\n\n\n\n[1]Add\n[2]Insert\n[3]Delete\n[4]Search\n[5]Visualize\n[6]Exit\n\n");
        printf( "Enter Option: " );
        scanf( "%d", &c );
        clearBuff();

        switch( c )
        {
            case 1:
                if( isFirst )
                {
                    initHead( &head, &count );
                    isFirst = 0;
                    break;
                }
                add( head, &count );
                break;
            case 2:
                insert( head, &count );
                break;
            case 4:
                searchByID( head, count );
                break;
            case 5:
                visualize( head, count );
                break;
            case 6:
                isQuit = 1;
                break;
        }
    }

}

int main()
{
    menu();
    return 0;
}