#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int * arr = malloc( sizeof( int ) * 2 );

	arr[ 0 ] = 1;
	arr[ 1 ] = 2;

	printf( "%d, %d\n", arr[ 0 ], arr[ 1 ] );
	
	int * temp = realloc( arr, sizeof( int ) * 3 );
	
	arr[ 2 ] = 3;

	printf( "%d, %d, %d\n", arr[ 0 ], arr[ 1 ], arr[ 2 ] );

	return 0;
}

