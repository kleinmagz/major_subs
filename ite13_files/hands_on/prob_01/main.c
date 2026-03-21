#include <stdio.h>
#include <stdlib.h>
#define FILE_NAME "numbers.txt"
#define DEST_FILE_NAME "sorted.txt"
void sortArray( int * arr, int size ){
	int i;
	int j;

	for( i = 0; i < size - 1; i++ ){
		for ( j = 0; j < size - ( i + 1 ); j++ ){
			if( arr[ j ] > arr[ j + 1 ] ) {
				int temp = arr[ j + 1 ];
				arr[ j + 1 ] = arr [ j ];
				arr[ j ] = temp;
			}
		}
	}

}

void printArray( int * arr, int n ){
	int i;

	printf( "Sorted array from file '%s': \n", FILE_NAME );

	for( i = 0; i < n; i++ ){
		printf( "[ %d ]\t: %d\n", i + 1, arr[ i ] );
	}
}

int * readFile( int * size ){
	int n = 1;
	int i = 0;
	int * arr = NULL;
	int temp;
	FILE * fptr = fopen( FILE_NAME, "r" );
	if( fptr == NULL ){
		printf( "Error:\tUnable to read file %s\n", FILE_NAME );
		exit( EXIT_FAILURE );
	}

	// allocates memory:
	arr = malloc( sizeof( int ) );

	// reads the file and assign it to an array:
	while( fscanf( fptr, " %d ", &temp ) != EOF ){
		arr[ i ] = temp;
		n++;
		arr = realloc( arr, n * sizeof( int ) );
		i++;
	}
	
	*size = n - 1;
	fclose( fptr );
	return arr;
}

void printInFile( int * arr, int n ){
	int i;
	FILE * fptr = fopen( DEST_FILE_NAME, "w" );
	if( fptr == NULL ){
		printf( "ERROR:\tUnable to write into file '%s'\n", DEST_FILE_NAME );
		exit( EXIT_FAILURE );
	}
	
	for( i = 0; i < n ; i++ ){
		fprintf( fptr, "[ %d ]\t: %d\n", i + 1, arr[ i ] );
	}

	fclose( fptr );
}


int main(){
	int n;
	int * numbers = readFile( &n );
	printf( "Size of array: %d\n", n );
	sortArray( numbers, n );
	printArray( numbers, n );
	printInFile( numbers, n );
	free( numbers );
	return 0;
}

