#include <stdio.h>
#include <stdlib.h>

struct nodes
{
    int x;
    struct nodes * next;
};

struct nodes * createNode()
{
    struct nodes * local = ( struct nodes * )malloc( sizeof( struct nodes ) );
    if( local == NULL )
    {     
        return NULL;
    }
    local->x = 0;
    local->next = NULL;
    return local;

}

void enqueue( struct nodes ** front, struct nodes ** rear, int value )
{
   if( *front == NULL && *rear == NULL )
   {
        (*front) = createNode();
        (*front)->x = value;
        *rear = *front;
   }
   else
   {
       (*rear)->next = createNode();
       (*rear)->next->x = value;
       *rear = (*rear)->next;
   }
}

void dequeue( struct nodes ** front, struct nodes ** rear )
{
    struct nodes * toDelete = NULL;
    int x;
    if( *front == NULL )
    {
        printf( "The queue is empty.\n" );
    }
    else
    {
        toDelete = *front;
        x = toDelete->x;
        if( *front == *rear )
        {
            free( toDelete );
            printf( "Front with x : %d has been deleted.\n", x );
            *front = NULL;
            *rear = NULL;
            return;
        }
        *front = (*front)->next;
        free( toDelete );
        printf( "Front with x : %d has been deleted.\n", x );
    }
}

// displays the queue from front to rear
void displayQueue( struct nodes * front )
{
    if( front == NULL )
    {
        printf( "[NULL]\n" );
        return;
    }
    while( front != NULL )
    {
        printf( "%d -> ", front->x );
        front = front->next;
    }
    printf( "\n" );
}

int main()
{
    struct nodes * front = NULL;
    struct nodes * rear = NULL;

    // n1->x = 10
    enqueue( &front, &rear, 10 );
    displayQueue( front );

    // n2->x = 15
    enqueue( &front, &rear, 15 );
    displayQueue( front );

    // n3->x = 25
    enqueue( &front, &rear, 25 );
    displayQueue( front );

    dequeue( &front, &rear );
    displayQueue( front );
    dequeue( &front, &rear );
    displayQueue( front );
    dequeue( &front, &rear );
    displayQueue( front );
    dequeue( &front, &rear );
    displayQueue( front );
    return 0;
}
