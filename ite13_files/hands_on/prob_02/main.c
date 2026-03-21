#include <stdio.h>
#include <stdlib.h>
#define COL_SIZE 3
#define ROW_SIZE 3
#define FILE_NAME "matrix_log.txt"

void readFromFile( int matrix[][ COL_SIZE ] ){
	int i, j;
	FILE * fptr = fopen( FILE_NAME, "r" );
	if ( fptr == NULL ){
		printf( "ERROR:\t Unable to open file %s\n", FILE_NAME );
		exit( EXIT_FAILURE );
	}
	
	for( i = 0; i < ROW_SIZE; i++ ){
		for( j = 0; j < COL_SIZE; j++ ){
			fscanf( fptr, " %d ", &matrix[ i ][ j ] );
		}
	}

	fclose( fptr );
}

void transposeMatrix( int matrix[][ COL_SIZE ] ){
	int i, j;

	// checks to see if the current cell is flipped; 0 - NOT, 1 - FLIPPED
	int is_cell_flipped[ ROW_SIZE ][ COL_SIZE ];

	for( i = 0; i < ROW_SIZE; i++ ){
		for( j = 0; j < COL_SIZE; j++ ){
			if( is_cell_flipped[ i ][ j ] == 1 ){
				continue;
			} else {
				int temp = matrix[ i ][ j ];
				matrix[ i ][ j ] = matrix [ j ][ i ];
				matrix[ j ][ i ] = temp;
				is_cell_flipped[ i ][ j ] = 1;
				is_cell_flipped[ j ][ i ] = 1;
			}
		}
	}
}

void printMatrix( int matrix[][ COL_SIZE ] ){
	int i, j;

	for( i = 0; i < ROW_SIZE; i++ ){
		printf( "\t" );
		for( j = 0; j < COL_SIZE; j++ ){
			printf( "%d ", matrix[ i ][ j ] );
		}
		printf( "\n" );
	}
}

void appendMatrix( int matrix[][ COL_SIZE ] ){
	int i, j;

	// opens file in append mode
	FILE * fptr = fopen( FILE_NAME , "a" );

	if( fptr == NULL ){
		printf( "ERROR:\t: Unable to write into file '%s'\n", FILE_NAME );
		exit( EXIT_FAILURE );
	}

	fprintf( fptr, "\n--- TRANSPOSED MATRIX ---\n" );

	for( i = 0; i < ROW_SIZE; i++ ){
		for( j = 0; j < COL_SIZE; j++ ){
			fprintf( fptr, "%d ", matrix[ i ][ j ] );
		}
		fprintf( fptr, "\n" );
	}

	fclose( fptr );
}

int main(){
	int matrix[ ROW_SIZE ][ COL_SIZE ];
	readFromFile( matrix );

	printf( "Original Matrix From File '%s': \n", FILE_NAME );
	printMatrix( matrix );
	printf( "\n" );

	transposeMatrix( matrix );
	printf( "Transposed Matrix From File '%s': \n", FILE_NAME );
	printMatrix( matrix );
	printf( "\n" );

	appendMatrix( matrix );

	return 0;
}
