#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR 64

// Programs that collect students' information.
// This program collect info of five students using structs and dynamic
// memory allocation.

typedef struct student
{
    int age;
    char idNumber[ 10 ];
    char firstName[ MAX_CHAR ];
    char lastName[ MAX_CHAR ];
}Student;

Student * input_info( int * count )
{
    printf( "How many students to enter?: " );
    scanf( "%d", count );
    getchar();

    Student * temp = ( Student * )malloc( *count * sizeof( Student ) );
    if( temp == NULL )
    {
        perror( "ERROR: Unable to allocate memory for Student * temp in Student * input( int * count )\n" );
        return NULL;
    }

    int i;
    for( i = 0; i < *count; i++ )
    {
        printf( "===INPUT STUDENT %d's INFORMATION====\n", i + 1 );
        printf( "Enter student age: " );
        scanf( "%d", &temp[ i ].age );
        getchar();

        printf( "Enter student id number (XXX-XXXXX): ");
        scanf( "%9[^\n]", temp[ i ].idNumber );
        getchar();

        printf( "Enter student first name: " );
        scanf( "%[^\n]", temp[ i ].firstName );
        getchar();

        printf( "Enter student last name: " );
        scanf( "%[^\n]", temp[ i ].lastName );
        getchar();
        printf( "====================================\n" );
    }

    return temp;
}

void print_info( Student * student, int count )
{
    int i;
    for( i = 0; i < count; i++ )
    {
        printf( "=============STUDENT %d==============\n", i + 1 );

        printf( "Student Age:\t\t%d\n", ( student + i )->age );
        printf( "Student ID Number:\t%s\n", ( student + i )->idNumber );
        printf( "Student First Name:\t%s\n", ( student + i )->firstName );
        printf( "Student Last Name:\t%s\n", ( student + i )->lastName );

        printf( "====================================\n" );

    }
}

int main()
{   
    int count = 0;
    Student * s = input_info( &count );
    if ( s == NULL )
    {
        return -1;
    }
    print_info( s, count );
    free( s );
    return 0;
}