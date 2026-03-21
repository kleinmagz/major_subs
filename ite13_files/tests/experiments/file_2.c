#include <stdio.h>
#include <stdlib.h>

#define	MAX_CHAR 50

int main(){
	char data_from_file[ MAX_CHAR ];
	char data[ MAX_CHAR ] = "Hello there!\n";
	FILE * fsrc = fopen( "file.txt", "r" );
	FILE * fdst = fopen( "file2.txt", "w" );

	if ( fsrc == NULL && fdst == NULL ){
		printf( "Files can't be accessed!\n" );
		exit( EXIT_FAILURE );
	}

	//fprintf( fp, "%s", data );
	//fprintf( fp, "Hi NIGGA!\n" );
	//fprintf( fp, "BITCH LASAGNA\n" );
	
	//fclose( fp );
	// Reading from file
	//fp = fopen( "./file.txt", "r" );	
	while( fgets( data_from_file, MAX_CHAR, fsrc ) != NULL ){
		fputs( data_from_file, fdst );
	}

	fclose( fdst );
	fclose( fsrc );
	
	printf( "Program success!\n " );
	return 0;
}


