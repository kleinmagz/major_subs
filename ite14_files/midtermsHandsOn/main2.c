#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct Node
{
    int data;
    struct Node * next;
} Node;


void Push( Node ** top, int value, int * size )
{
    if( *size > 100 )
    {
        printf( "Exceeded maximum stack size.\n" );
        return;
    }
    Node * new  = ( Node * )malloc( sizeof( Node ) );
    if( new == NULL )
    {
        printf( "E: Failed to allocate memory.\n" );
        return;
    }
    new->data = value;
    new->next = NULL;

    if( *top == NULL )
    {
        *top = new;
        return;
    }
    new->next = *top;
    *top = new;
    ( *size )++;
}

void Pop( Node ** top, int * size )
{
    Node * delete = *top;
    if( delete == NULL )
        return;
    *top = ( *top )->next;
    free( delete );
    ( *size )--;
}

int main()
{
    char * arr[] = { "2", "3", "1", "*", "+", "9", "-" };
    int n = sizeof( arr ) / sizeof( arr[ 0 ] );
    Node * top = NULL;
    int size = 0;
    int result;
    int i;

    for( i = 0; i < n; i ++ )
    {
        if( isdigit( arr[ i ] ) )
            Push( &top, arr[ i ] - "0", &size );
        else
        {
            int temp;
            if( arr[ i ] == "+" )
                temp = top->next->data + top->data;
            else if( arr[ i ] == "-" )
                temp = top->next->data - top->data;
            else if( arr[ i ] == "*" )
                temp = top->next->data * top->data;
            
            Pop( &top, &size );
            Pop( &top, &size );
            Push( &top, temp, &size );
        }
    }

    result = top->data;
    printf( "Result = %d\n", result );

}