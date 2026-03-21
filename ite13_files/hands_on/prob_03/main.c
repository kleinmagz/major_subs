#include <stdio.h>
#include <stdlib.h>
#define READ_FN "scores.txt"
#define WRITE_FN "passers.txt"

const int COLS = 2;

// rows are the student_count

int * loadScores( int * student_count ){
    FILE * fileptr = NULL;
    int * scores = NULL;
    int count = 0;
    int i, j;
    int temp;

    fileptr = fopen( READ_FN, "r" );
    if( fileptr == NULL ){
        printf( "ERROR:\tUnabe to open file '%s'.\n", READ_FN );
        exit( EXIT_FAILURE );
    }

    // counts total students in scores.txt
    while( fscanf( fileptr, " %d %d", &temp, &temp ) != EOF ){
        count++;
    }

    // allocates memory dynamically
    scores = ( int * )malloc( sizeof( int ) * count * COLS );
    if( scores == NULL ){
        printf( "ERROR:\tFailed to allocate memory for scores in function: loadScores().\n " );
        exit( EXIT_FAILURE );
    }

    // points the file pointer back to the start of the file
    // after we counted the number of students earlier.
    fseek( fileptr, 0, SEEK_SET );

    // fills the dynamic array with data from file
    for( i = 0; i < count; i++ ){
        for( j = 0; j < COLS; j++ ){
            if( fscanf( fileptr, " %d" , &scores[ i * COLS + j ] ) != 1 ){
                printf( "ERROR:\tUnexpected data type encountered in file: '%s'. Must be type: INT\n", READ_FN );
                scores[ i * COLS + j ] = -1;
            }
        }
    }

    *student_count = count;
    fclose( fileptr );
    return scores;
}

float calculateAverage( int student_count, int * scores ){
    int i;
    int score_sum = 0;

    for( i = 0; i < student_count; i++ ){
        score_sum += scores[ i * COLS + 1 ];
    }
    
    return ( float )score_sum / student_count;
}

void printPassers( int * scores, float average, int student_count ){
    int i, j = 1;
    FILE * fileptr = NULL;

    fileptr = fopen( WRITE_FN, "w" );
    if( fileptr == NULL ){
        printf( "ERROR:\tUnable to open file '%s'.\n", WRITE_FN );
        return;
    }

    fprintf( fileptr, "--- PASSERS ---\n" );

    for( i = 0; i < student_count; i++ ){
        if( scores[ i * COLS + 1 ] >= average ){
            fprintf( fileptr, "\t[%d] ID: %d\t SCORE: %d\n", j++, scores[ i * COLS ], scores[ i * COLS + 1 ] );
        }
    }

    printf( "Passers identified!\nPlease check in file '%s'.\n", WRITE_FN );
}

int main(){
    int student_count = 0;
    int * score_record = loadScores( &student_count );
    float class_average = calculateAverage( student_count, score_record );
    printPassers( score_record, class_average, student_count );
    free( score_record );
    return 0;
}
