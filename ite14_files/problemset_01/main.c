#include <stdio.h>
#include <stdlib.h>
#define MAX_CHAR 64

// Student structure
typedef struct student
{
    int studentID;
    float GPA;
    char name[ MAX_CHAR ];
} Student;


// Initialize the student array to be a dynamic array.
void init( Student * s )
{
    s = ( Student * )malloc( sizeof( Student ) );
    if( s == NULL )
    {
        perror( "E: Failed to allocate memory in void init( Student *s)\n");
        exit( EXIT_FAILURE );
    }
}

// Clears any unwanted characters in the input buffer
// if the user enters too many.
void clearBuffer()
{
    int c;
    while( ( c = getchar() ) != '\n' && c != EOF );
}

Student * inputStudents( int * count )
{
    int i;
    Student * temp = NULL;

    printf( "Enter number of students to input: " );
    scanf( "%d", count );
    getchar();

    temp = ( Student * )realloc( temp, *count );
    if( temp == NULL )
    {
        perror( "E: Failed to reallocate memory in Student *inputStuddents(int *count)\n" );
        exit( EXIT_FAILURE );
    }

    for( i = 0; i < *count; i++ )
    {
        printf( "=====STUDENT %d INFO=====\n", i + 1 );
        printf( "Enter student ID (max 8 digits): " );
        scanf( "%8d", &temp[ i ].studentID );
        clearBuffer();
        printf( "Enter student name: " );
        scanf( "%[^\n]", temp[ i ].name );
        clearBuffer();
        printf( "Enter student GPA: " );
        scanf( "%4f", &temp[ i ].GPA );
        clearBuffer();
        printf( "=========================\n\n" );
    }
    return temp;
}

int search( Student * s, int target, int count )
{
    int i;

    for( i = 0; i < count; i++ )
    {
        if( s[ i ].studentID == target )
            return i;
    }

    return -1;
}

void printResults( Student * s, int count )
{
    int index, target;

    printf( "Enter ID: " );
    scanf( "%8d", &target );
    clearBuffer();
    printf( "\n" );
    
    index = search( s, target, count );
    if( index < 0 )
    {
        printf( "Student with ID %d does not exist.\n\n", target );
        return;
    }

    printf( "Student Found!\nStudent Info:\n" );
    printf( "Student ID:\t%d\n", s[ index ].studentID );
    printf( "Student Name:\t%s\n", s[ index ].name );
    printf( "Student GPA:\t%.2f\n\n", s[ index ].GPA ); 
}

void run()
{
    Student * students = NULL;
    int count = 0; int choice;

    init( students );
    while( 1 )
    {
        printf( "=====STUDENT RECORD SYSTEM=====\n" );
        printf( "[1]Enter Student Info\n[2]Search By ID\n[3]Exit\n" );
        printf( "Enter option: " );
        scanf( "%d", &choice );
        printf( "\n" );

        switch ( choice )
        {
            case 1:
                students = inputStudents( &count );
                break;
            case 2:
                printResults( students, count );
                break;
            case 3:
                printf( "Bye!\n" );
                free( students );
                return;
                break;
            default:
                printf( "Invalid input.\n\n" );
                clearBuffer();
        }
    }
}


int main()
{   
    run();
    return 0;
}