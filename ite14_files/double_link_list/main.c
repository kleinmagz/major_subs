#include <stdio.h>
#include <stdlib.h>

struct nodes{
    int x;
    struct nodes * lnode;
    struct nodes * rnode;
};

// Doubly linked list
typedef struct node{
    int x;
    struct node * next;
    struct node * prev;
} Node;

void displayNodes( Node * curr )
{   
    if( curr == NULL )
    {
        printf( "[Nothing to display]\n" );;
        return;
    }

    while( curr != NULL )
    {
        printf( "%d -> ", curr->x );
        curr = curr->next;
    }
    printf( "\n" );
}

Node * createNode()
{
    Node * newNode = ( Node * )malloc( sizeof( Node ) );
    if( newNode == NULL )
    {
        printf( "Memory allocation failed.\n" );
        return NULL;
    }
    printf( "Enter x: " );
    scanf( "%d", &newNode->x );
    return newNode;
}

void addNode( Node ** head )
{
    if( *head == NULL )
    {
        *head = createNode();
        ( *head )->prev = NULL;
        ( *head )->next = NULL;
        return;
    }

    Node * curr = *head;
    Node * next = curr->next;
    Node * prev = curr->prev;

    while( curr->next != NULL )
    {
        prev = curr;
        curr = curr->next;
        next = curr->next;
    }

    curr->next = createNode();
    prev = curr;
    curr = curr->next;
    curr->prev = prev;
    curr->next = NULL;
}

void insertNode( Node ** head )
{
    if( *head == NULL )
    {
        addNode( head );
        return;
    }

    int i = 0;
    int target;
    Node * newNode = NULL;
    Node * prev = NULL;
    Node * next = NULL;
    Node * curr = *head;
    printf( "Enter index: " );
    scanf( "%d", &target );
    newNode = createNode();

    if( target == 0 )
    {
        curr->prev = newNode;
        *head = newNode;
        ( *head )->next = curr;
        ( *head )->prev = NULL;
        return;
    }

    while( curr != NULL )
    {
        i++;
        if( i == target )
        {
            prev = curr;
            next = curr->next;
            curr->next = newNode;
            newNode->next = next;
            newNode->prev = prev;
            return;
        }

        if( curr->next == NULL )
        {
            prev = curr;
            curr->next = newNode;
            newNode->next = NULL;
            newNode->prev = prev;
            return;
        }
        curr = curr->next;
    }
}

void deleteNode( Node ** head )
{
    if( *head == NULL )
    {
        printf( "There is nothing to delete.\n" );
        return;
    }

    int i = 0;
    int target;
    Node * deleteNode = NULL;
    Node * curr = *head;
    printf( "Enter index to delete: " );
    scanf( "%d", &target );

    if( target == 0 )
    {
        deleteNode = *head;
        curr = curr->next;
        curr->prev = NULL;
        free( deleteNode );
        *head = curr;
        return;
    }
    while( curr != NULL )
    {
        if( i == target && curr->next != NULL )
        {
            deleteNode = curr;
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            free( deleteNode );
            return;
        }
        
        if( curr->next == NULL )
        {
            deleteNode = curr;
            curr->prev->next = NULL;
            free( deleteNode );
            return;
        }
        curr = curr->next;
        i++;
    }
}

int main()
{
    Node * head = NULL;
    int ch;
    int isRunning = 1;

    while( isRunning )
    {
        displayNodes( head );
        printf( "[1]Add\n[2]Insert Node\n[3]Delete Node\n[4]Exit\n" );
        printf( "Enter option: " );
        scanf( "%d", &ch );

        switch( ch )
        {
            case 1:
                addNode( &head );
                break;
            case 2:
                insertNode( &head );
                break;
            case 3:
                deleteNode( &head );
                break;
            case 4:
                isRunning = 0;
                break;
            default:
                break;
        }
    }

    return 0;
}

// int main()
// {
//     struct nodes *n1, *n2, *n3,*head;
//     n1 = (struct nodes *)malloc(sizeof(struct nodes));
//     n2 = (struct nodes *)malloc(sizeof(struct nodes));
//     n3 = (struct nodes *)malloc(sizeof(struct nodes));
    
//     n1->x = 10;
//     n2->x = 20;
//     n3->x = 30;

//     n1->lnode = NULL;
//     n1->rnode = n2;
//     n2->lnode = n1;
//     n2->rnode = n3;
//     n3->lnode = n2;
//     n3->rnode = NULL;

//     head = n1;

//     struct nodes * n4 = (struct nodes *)malloc(sizeof(struct nodes));
//     n4->x = 40;
//     struct nodes * curr = head;
//     printf("work\n");
    
//     n4->rnode = curr;
//     n4->lnode = NULL;
//     head = n4;
//     curr = head;

//     printf("work\n");
//     struct nodes * n5 = (struct nodes *)malloc(sizeof(struct nodes));
//     n5->x = 50;
//     while(curr != NULL)
//     {
//         if(curr->rnode == NULL)
//         {
//             curr->rnode = n5;
//             curr->rnode->lnode = curr;
//             curr = curr->rnode;
//             curr->rnode = NULL;
//         }
//         curr = curr->rnode;
//     }
//     printf("work\n");
//     curr = head;

//     while( curr != NULL )
//     {
//         if( curr->rnode->x == 30 || curr->rnode->x == 50 )
//         {
//             curr->rnode->rnode->lnode = curr;
//             curr->rnode->rnode->rnode = curr->rnode->rnode->rnode->rnode;
//             free(curr->rnode);
//         }
//         curr = curr->rnode;
//     }
//     printf("work\n");
// }