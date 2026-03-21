#include <stdio.h>
#define MAX_CHAR 64

// Programs that collect students' information.
// This program collect info of 5 students in 2d Array.


void input_info( int * age, char (*id)[ 10 ], char (* fname)[ MAX_CHAR ], char (* lname)[ MAX_CHAR ], int count )
{
    int i;
    for( i = 0; i < count; i++ )
    {
        printf( "===INPUT STUDENT %d's INFORMATION====\n", i + 1 );
        printf( "Enter student age: " );
        scanf( "%d", &age[ i ] );
        getchar();

        printf( "Enter student id number (XXX-XXXXX): ");
        scanf( "%9[^\n]", id[ i ] );
        getchar();

        printf( "Enter student first name: " );
        scanf( "%[^\n]", fname[ i ] );
        getchar();

        printf( "Enter student last name: " );
        scanf( "%[^\n]", lname[ i ] );
        getchar();
        printf( "====================================\n" );
    }

}

void print_info( int * age, char (*id)[ 10 ], char (* fname)[ MAX_CHAR ], char (* lname)[ MAX_CHAR ], int count )
{
    int i;
    for( i = 0; i < count; i++ )
    {
        printf( "=============STUDENT %d==============\n", i + 1 );

        printf( "Student Age:\t\t%d\n", age[ i ]);
        printf( "Student ID Number:\t%s\n", id[ i ] );
        printf( "Student First Name:\t%s\n", fname[ i ] );
        printf( "Student Last Name:\t%s\n", lname[ i ] );

        printf( "====================================\n" );

    }
    
}

int main()
{   
    const int studentsCount = 5;
    int age[ 5 ];
    char idNumbers[ 5 ][ 10 ];
    char firstNames[ 5 ][ MAX_CHAR ];
    char lastNames[ 5 ][MAX_CHAR ];

    input_info( age, idNumbers, firstNames, lastNames, studentsCount );
    print_info( age, idNumbers, firstNames, lastNames, studentsCount );


    return 0;
}