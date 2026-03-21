#include <stdio.h>
#include <string.h>

// To keep track on the number of books instanced.
// Used to display the correct "enumerator" in display_book
static int book_count = 0;

struct Book_data {
    char title[ 50 ];
    char author[ 50 ];
    int year;
};

void display_book( struct Book_data b ){
    // Increments and display correct "enumerator"
    printf( "Book Record %d:\n", ++book_count );
    printf( "Title: %s\n", b.title );
    printf( "Author: %s\n", b.author );
    printf( "Year: %d\n\n", b.year );
}

int main(){
    struct Book_data book1;

    strcpy( book1.title, "C Programming Learn to Code" );
    strcpy( book1.author, "Sisir Kumar Jena" );
    book1.year = 2022;


    // Static array of structures
    struct Book_data library[ 2 ];

    // Area 3: Array member initialization
    strcpy( library[ 0 ].title, "Learn C the Hard Way" );
    strcpy( library[ 0 ].author, "Zed A. Shaw" );
    library[ 0 ].year = 2016;

    // Personalization
    strcpy( library[ 1 ].title, "Animal Farm" );
    strcpy( library[ 1 ].author, "George Orwell" );
    library[ 1 ].year = 1945;

    // Display books
    display_book( book1 );
    display_book( library[ 0 ] );
    display_book( library[ 1 ] );

    return 0;
}