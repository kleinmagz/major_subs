#include <stdio.h>
#define MAX_CHAR 64

// Programs that collect students' information.
// This program collect info of only one student.

void input_info( int * age, char * id, char * fname, char * lname )
{
    printf( "Enter student age: " );
    scanf( "%d", age );
    getchar();

    printf( "Enter student id number (XXX-XXXXX): ");
    scanf( "%9[^\n]", id );
    getchar();

    printf( "Enter student first name: " );
    scanf( "%[^\n]", fname );
    getchar();

    printf( "Enter student last name: " );
    scanf( "%[^\n]", lname );
    getchar();
}

void print_info( int * age, char * id, char * fname, char * lname )
{
    printf( "Student Age:\t\t%d\n", *age );
    printf( "Student ID Number:\t%s\n", id );
    printf( "Student First Name:\t%s\n", fname );
    printf( "Student Last Name:\t%s\n", lname );
}

int main()
{
    int age;
    char idNumber[ 10 ];
    char firstName[ MAX_CHAR ];
    char lastName[ MAX_CHAR ];

    input_info( &age, idNumber, firstName, lastName );
    print_info( &age, idNumber, firstName, lastName );

    return 0;
}