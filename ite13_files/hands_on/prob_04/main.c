#include <stdio.h>
#include <stdlib.h>
#define IN_FILE "temps.in"
#define OUT_FILE "daily_report.out"
#define DEGREE "\u00B0"
#define TRUE 1
#define FALSE 0

const int HOURLY_READINGS = 24;

FILE * openFile( const char * file_name, const char * mode ){
    FILE * fptr = fopen( file_name, mode );
    
    if( fptr == NULL ){
        printf( "ERROR:\tUnable to open or find file '%s'.\n", file_name );
        exit( EXIT_FAILURE );
    }
}

void loadTemps( float * temp ){
    int i;
    FILE * fptr = NULL;

    fptr = openFile( IN_FILE, "r" );

    for( i = 0; i < HOURLY_READINGS; i++ ){
        if( fscanf( fptr, " %f", &temp[ i ] ) == EOF ){
            break;
        }
    }

    fclose( fptr );
}

void determineMaxMinTemp( float * max, float * min, float * temps ){
    float current_max, current_min;
    int i;

    current_max = current_min = temps[ 0 ];

    for( i = 0; i < HOURLY_READINGS; i++ ){
        if( current_max < temps[ i ] ){
            current_max = temps[ i ];
        }

        if( current_min > temps[ i ] ){
            current_min = temps[ i ];
        }
    }

    *max = current_max;
    *min = current_min;
}

float calculateAveTemp( float * temps ){
    int i;
    float sum = 0;
    for( i = 0; i < HOURLY_READINGS; i++ ){
        sum += temps[ i ];
    }

    return sum / ( float )HOURLY_READINGS;
}

void generateReport( float max, float min, float ave ){
    FILE * fptr = NULL;

    fptr = openFile( OUT_FILE, "w" );

    fprintf( fptr, "-- DAILY REPORT --\n" );
    fprintf( fptr, "Maximum Temperature:\t%.1f" DEGREE "C\n", max );
    fprintf( fptr, "Minimum Temperature:\t%.1f" DEGREE "C\n", min );
    fprintf( fptr, "Average Temperature:\t%.1f" DEGREE "C\n", ave );

    fclose( fptr );
}

int main(){
    float average_temp;
    float max_temp;
    float min_temp;
    float temps[ HOURLY_READINGS ];

    loadTemps( temps );
    determineMaxMinTemp( &max_temp, &min_temp, temps);
    average_temp = calculateAveTemp( temps );
    generateReport( max_temp, min_temp, average_temp );

    printf( "Successfully generated report. Please see in file '%s'.\n", OUT_FILE );
    return 0;
}