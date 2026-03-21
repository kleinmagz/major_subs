#include <stdio.h>
#include <stdlib.h>

typedef struct point
{
    int id;
    int x;
    int y;
    //struct point * prev;
    struct point * next;
}Point;

void clearBuff()
{
    char c;
    while( (c = getchar() ) != '\n' && c != EOF );
}

void clearScr()
{
    printf( "\033[H\033[2J" );
}

Point * initHead( int x, int y, int * c )
{
    Point * p = ( Point * )malloc( sizeof( Point ) );
    if( p == NULL )
    {
        perror( "E: Memory allocation failed in Point *initHead(int x, int y)\n" );
        return NULL;
    }

    p->id = 1;
    p->x = x;
    p->y = y;
    //p->prev = NULL;
    p->next = NULL;
    
    *c = 1;
    return p;
}

void add( Point ** current, int * count )
{
    Point * p = ( Point * )malloc( sizeof( Point ) );
    if( p == NULL )
    {
        perror( "E: Memory Allocation failed at void add( Point **current)\n" );
        return;
    }
    
    p->next = NULL;
    p->id = ++(*count);
    clearScr();
    printf( "\n\n\n\nEnter x: " );
    scanf( "%d", &p->x );
    clearBuff();
    printf( "Enter y: " );
    scanf( "%d", &p->y );
    clearBuff();
    
    (*current)->next = p;
    (*current) = p;
    //p->prev = (*current);
}

void insert( Point ** current, Point ** head, int count )
{   
    int indexAfter;

    printf( "Enter index to insert after: " );
    scanf( "%d", &indexAfter );
    *current = *head;

}

void search( Point * curr )
{       
    int id;

    clearScr();
    printf( "\n\n\n\nEnter id: " );
    scanf( "%d", &id );
    clearBuff();
    
    while( curr != NULL )
    {
        if( curr->id == id )
        {
             clearScr();
             printf( "\n\n\n\nPoint.id: %d\nPoint.x: %d\nPoint.y: %d\n\n",curr->id, curr->x, curr->y );
             getchar();
             return;            
        }

        curr = curr->next;
    }
    
    printf("Point does not exist.\n");
    getchar();
    return;
}

void menu()
{
    Point * head = NULL;
    Point * current = NULL;
    //Point * prev = NULL;
    //Point * next = NULL;
    int c, isFirstTime = 1; int isQuit = 0; int count = 0;

    while( !isQuit )
    {
        clearScr();
        printf( "\n\n\n\n[1]Add\n[2]Insert\n[3]Delete\n[4]Search\n[5]Exit\n\n" );
        printf( "Enter option: " );
        scanf( "%d", &c );
        clearBuff(); 

        switch( c )
        {
            case 1:
                if( isFirstTime )
                {
                    int x, y;
                    clearScr();
                    printf( "\n\n\n\nEnter x: " );
                    scanf( "%d", &x );
                    clearBuff();
                    printf( "Enter y: " );
                    scanf( "%d", &y );
                    clearBuff();
                    head = initHead( x, y, &count );
                    current = head;

                    isFirstTime = 0;

                    break;
                }
                add( &current, &count );
                break;

            case 4:
                search( head );
                break;
            
            case 5:
                isQuit = 1;
                break;
        }

    }
}

int main(){
    menu();
    return 0;
}