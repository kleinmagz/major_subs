#include <stdio.h>
#include <stdlib.h>

const int MAX_NUMS = 5;

int loadSet( int set[], const char * file_name){
    FILE * fptr = fopen( file_name, "r" );
    int i;

    if( fptr == NULL ){
        printf( "ERROR:\tUnable to open file '%s'.\n", "setA.txt" );
        exit( EXIT_FAILURE );
    }

    for( i = 0; i < MAX_NUMS; i++ ){
        if( !fscanf( fptr, " %d", &set[ i ] ) ){
            printf( "WARNING:\tUnexpected type identified. Must be type INT.\n");
            return 0;
        }
    }

    fclose( fptr );
    return 1;
}

void mergeSets( int setA[], int setB[], int merged[], int * size ){
    int i;
    int pos = 0;
    int frequency[ MAX_NUMS * 2 ];

    for( i = 0; i < MAX_NUMS * 2; i++ ){
        frequency[ i ] = 0;
    }

    // load set A
    for( i = 0; i < MAX_NUMS; i++ ){
        merged[ pos++ ] = setA[ i ];
        frequency[ ( ( setA[ i ] ) / 10 ) - 1 ] = 1;
    }

    // load setB
    for( i = 0; i < MAX_NUMS; i++){
        if( frequency[ ( ( setB[ i ] ) / 10 ) - 1 ] == 1 ){
            continue;
        }
        merged[ pos++ ] = setB[ i ];
        frequency[ ( ( setB[ i ] ) / 10 ) - 1 ] = 1;
    }

    *size = pos;
}

void generateFile( int merged[], int n ){
    int i;
    FILE * fptr = fopen( "merged.txt", "w" );

    if( fptr == NULL ){
        printf( "ERROR:\tUnable to open file '%s'.\n", "merged.txt" );
        exit( EXIT_FAILURE );
    }

    fprintf( fptr, "MergedSet: \n" );

    for( i = 0; i < n; i++ ){
        fprintf( fptr, "%d\n", merged[ i ] );
    }

    fclose( fptr );
}

int main(){
    int setA[ MAX_NUMS ];
    int setB[ MAX_NUMS ];
    int merged[ MAX_NUMS * 2 ];
    int size;

    if( !( loadSet( setA, "setA.txt" ) && loadSet( setB, "setB.txt" ) ) ){
        printf( "ERROR:\tFailed to load sets. Please recheck files and refactor to proper format.\n" );
        return -1;
    }
    else{
       mergeSets( setA, setB, merged, &size );
    }

    generateFile( merged, size );

    printf( "Successfully merged sets!\n" );

    return 0;
}