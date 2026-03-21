// KLEIN TIMOTHY A. MAGALLANO
// ITE13 BC1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// NOTE TO SELF: compile this using this command:
// 	gcc main.c -o main -lm

int is_pronic( int num );

int * find_pronic_in_range( int low, int high, int * count );

void process_ranges( const char * filename );

void print_array( int * arr, int count, int low, int high );

int main(){
	process_ranges( "./ranges.txt" );
	return 0;
}

int is_pronic( int num ){
	int n;

	if( num == 0 ){
		return 1;
	}

	n = floor( sqrt( num ) );

	if( ( n * ( n + 1 ) ) == num ){
		return 1;
	}
	else{
		return 0;
	}
}

int * find_pronic_in_range( int low, int high, int * count ){
	int i;
	int * pronics = NULL;
	*count = 0;

	for( i = low; i <= high; i++ ){
		if ( is_pronic( i ) ){
			( *count )++;
			pronics = realloc( pronics, ( *count ) * sizeof( int ) );
			if( pronics == NULL ){
				printf( "Unable to reallocate memory.\n" );
				exit( EXIT_FAILURE );
			}
			pronics[ ( *count ) - 1 ] = i;
		}
	}

	return pronics;
}

void process_ranges( const char  * filename ){
	int count, low, high, test_cases, i;
	FILE * fileptr = fopen( filename, "r" );
	int * pronic_numbers = NULL;

	if( fileptr == NULL ){
		printf( "Unable to access file: %s\n", filename );
		exit( EXIT_FAILURE );
	}

	if( !( fscanf( fileptr, "%d", &test_cases ) ) ){
		printf( "Unable to read data from file: %s\n", filename );
		exit( EXIT_FAILURE );
	}

	for( i = 0; i < test_cases; i++ ){
		if( ( fscanf( fileptr, "%d %d", &low, &high ) ) != 2 ){
			printf( "Invalid file format! in file: %s\n", filename );
			exit( EXIT_FAILURE );
		}
		pronic_numbers = find_pronic_in_range( low, high, &count );
		print_array( pronic_numbers, count, low, high );
		count = 0;
	}
	
	free( pronic_numbers );
	fclose( fileptr );
}

void print_array( int * arr, int count, int low, int high ){
	int i;

	if( count == 0 ){
		printf( "No Pronic numbers found in range( %d - %d )\n", low, high );
		return;
	}
	
	printf( "Pronic numbers from range( %d - %d ) : ", low, high );

	for( i = 0; i < count; i++ ){
		if( ( i + 1 ) == count ){
			printf( "%d", arr[ i ] );
		}
		else{
			printf( "%d, ", arr[ i ] );
		}
	}

	printf( "\n" );
}



