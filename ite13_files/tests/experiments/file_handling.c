#include <stdio.h>
#include <stdlib.h>

int main(){
	
	FILE * fptr = NULL;
	
	char data_from_file[ 50 ];
	char data[ 50 ] = "Hello World! Carga State University!";

	fptr = fopen( "./file.txt", "w" );

	if( fptr == NULL ){
		printf( "File cannot be opened!\n" );
	}
	else{
		printf( "The file is opened!\n" );
		
		fputs( data, fptr );
		fputs( "\n", fptr );

		fptr = fopen( "./file.txt", "r" );

		while ( fgets( data_from_file, 50, fptr ) != NULL ){
			printf( "%s", data_from_file );
		}

		fptr = fopen( "./file.txt", "w" );

		fseek( fptr, -1 , SEEK_END );
		fputs( "YEET!", fptr );

		fptr = fopen( "./file.txt", "r" );

		while ( fgets( data_from_file, 50, fptr ) != NULL ){
			printf( "%s", data_from_file );
		}

		fclose( fptr );

		printf( "Data successfully written in the file!\n" );
		printf( "The file is now closed.\n" );
	}

	return 0;
}
