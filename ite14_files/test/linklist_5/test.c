#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node * next;
}Node;

void Push( Node ** top, int value )
{
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
}

void Pop( Node ** top )
{
    Node * delete = *top;
    if( delete == NULL )
        return;
    *top = ( *top )->next;
    free( delete );
}

int main()
{
    char arr[] = { '2', '3', '1', '*', '+', '9', '-' };
    Node * top = NULL;
    int result;
    int n = sizeof( arr ) / sizeof( arr[ 0 ] );
    int i;

    for( i = 0; i < n; i ++ )
    {
        if( isdigit( arr[ i ] ) )
            Push( &top, arr[ i ] - '0' );
        else
        {
            int temp;
            if( arr[ i ] == '+' )
                temp = top->next->data + top->data;
            else if( arr[ i ] == '-' )
                temp = top->next->data - top->data;
            else if( arr[ i ] == '*' )
                temp = top->next->data * top->data;
            
            Pop( &top );
            Pop( &top );
            Push( &top, temp );
        }
    }

    result = top->data;
    printf( "Result = %d\n", result );
}