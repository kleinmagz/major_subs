#include <stdio.h>
#define MAX_CHAR 64

// Programs that collect students' information.
// This program collect info of only one student using structs.

typedef struct student
{
    int age;
    char idNumber[ 10 ];
    char firstName[ MAX_CHAR ];
    char lastName[ MAX_CHAR ];
}Student;

void input_info( Student * student )
{
    printf( "Enter student age: " );
    scanf( "%d", &student->age );
    getchar();

    printf( "Enter student id number (XXX-XXXXX): ");
    scanf( "%9[^\n]", student->idNumber );
    getchar();

    printf( "Enter student first name: " );
    scanf( "%[^\n]", student->firstName );
    getchar();

    printf( "Enter student last name: " );
    scanf( "%[^\n]", student->lastName );
    getchar();
}

void print_info( Student * student )
{
    printf( "Student Age:\t\t%d\n", student->age );
    printf( "Student ID Number:\t%s\n", student->idNumber );
    printf( "Student First Name:\t%s\n", student->firstName);
    printf( "Student Last Name:\t%s\n", student->lastName );
}

int main()
{
    Student s1;
    input_info( &s1 );
    print_info( &s1 );

    return 0;
}