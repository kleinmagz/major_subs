#include <stdio.h>
#include <stdlib.h>

int main(){
	
	FILE * fin = fopen( "./main.c", "r" );
	//FILE * fdup = fopen( "Dupler.c", "w" ):

	char str[ 201 ];
	
	if( fin == NULL ){
		printf( "Warning: FIles do not exist." );
		return 0;
	}

	//fgets( str, 201, fin );
	//printf( "%s\n", str );


	/*if( fin == NULL || fdup == NULL ){
		printf( "Warning: Files do not exist." );
		return 0;
	}
	*/
	
	while( fgets( str, 200, fin ) != NULL ) {
		printf( "%s", str );
	}
	

	fclose( fin );

	return 0;
}
