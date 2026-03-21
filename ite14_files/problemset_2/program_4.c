#include <stdio.h>
#define MAX_CHAR 64

// Programs that collect students' information.
// This program collect info of five students using array of structs.

typedef struct student
{
    int age;
    char idNumber[ 10 ];
    char firstName[ MAX_CHAR ];
    char lastName[ MAX_CHAR ];
}Student;

void input_info( Student * student, int count )
{
    int i;
    for( i = 0; i < count; i++ )
    {
        printf( "===INPUT STUDENT %d's INFORMATION====\n", i + 1 );
        printf( "Enter student age: " );
        scanf( "%d", &student[ i ].age );
        getchar();

        printf( "Enter student id number (XXX-XXXXX): ");
        scanf( "%9[^\n]", student[ i ].idNumber );
        getchar();

        printf( "Enter student first name: " );
        scanf( "%[^\n]", student[ i ].firstName );
        getchar();

        printf( "Enter student last name: " );
        scanf( "%[^\n]", student[ i ].lastName );
        getchar();
        printf( "====================================\n" );
    }
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
    const int count = 5;
    Student s[ count ];
    input_info( s, count );
    print_info( s, count );

    return 0;
}