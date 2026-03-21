#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_CHAR 64

typedef struct node{
    char name[ MAX_CHAR ];
    float gpa;
    int id;
} Student;

Student * next = NULL;

void addStudent(){
    
}
void deleteStudent( Student ** head );
void searchStudent( Student * head );
void getAverage( Student * head );
void displayStudents( Student * head );

int main() {
    Student * head = NULL;
    bool isRunning = true;
    int choice;
    while( isRunning ){
        printf( "[1] Add Student\n[2] Delete Student\n[3] Search Student\n[4] Average\n[5] Display\n\n");
        printf( "Enter Choice: " );
        scanf( "%d", &choice );

        switch( choice ){
            case 1:

        }
    }

    return 0;
}