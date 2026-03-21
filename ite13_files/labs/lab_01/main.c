#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define FILENAME "data.csv"
#define MAX_RECORDS	3

// TIME
typedef struct{
	int hour, minute;
} TIME;

// Daily Record
typedef struct{
	char employee_id[ 10 ];
	char date[ 12 ];
	TIME time_in, time_out;
	unsigned int tardiness_minutes;
	int total_work_minutes;
	unsigned int undertime_minutes;
} DailyRecord;



int time_to_minutes( TIME t ){
	return ( t.hour * 60 ) + t.minute;
}


// calculates the tardiness of the employee in minutes
int calculate_tardiness( TIME actual_in ){
	TIME start_time;
	start_time.hour = 8;
	start_time.minute = 0;
	int time_start = time_to_minutes( start_time );
	int emp_time_in = time_to_minutes( actual_in );
	int total_tardiness = emp_time_in - time_start;

	if( total_tardiness < 0 ){
        return 0;
	}else{
        return emp_time_in - time_start;
	}
}

int calculate_total_work_minutes( TIME in, TIME out ){
    int lunch_break = 60;
    int in_minutes = time_to_minutes( in );
    int out_minutes = time_to_minutes( out );
    return ( out_minutes - in_minutes ) - lunch_break;
}

int convert_hr_to_min( int minutes ){
    return minutes / 60;
}

unsigned int calculate_undertime_minutes( int required_work_mins, int total_work_mins ){
    int undertime_mins = required_work_mins - total_work_mins;
    if( undertime_mins < 0 ){
        return 0;
    }else{
        return required_work_mins - total_work_mins;
    }

}

void display_record( const DailyRecord * r, int index ){
    int work_hours = convert_hr_to_min( r->total_work_minutes );
    int mins = ( r->total_work_minutes) - ( work_hours * 60 );
    printf( "Record %d( ID: %s, Date: %s ):\n", index + 1, r->employee_id, r->date );
    printf( "\t Time In: %d:%d, Time Out: %d:%d\n", r->time_in.hour, r->time_in.minute, r->time_out.hour, r->time_out.minute );
    printf( "\tTardiness: %d minutes\n", r->tardiness_minutes );
    printf( "\tUndertime: %d minutes\n", r->undertime_minutes );
    printf( "\tTotal Work: %d minutes( %d hrs, %d mins )\n", r->total_work_minutes, work_hours, mins );
}

DailyRecord * load_records( int * count ){
	FILE * file = fopen( FILENAME, "r" );
	if ( file == NULL ){
		fprintf( stderr, "Error: Could not open file.\n" );
		*count = 0;
		return NULL;
	}

	DailyRecord * records = calloc( MAX_RECORDS, sizeof( DailyRecord ) );
	if( records == NULL ){
		printf( "Error: Could not allocate memory\n" );
		*count = 0;
		exit( EXIT_FAILURE );
	}

	int record_count = 0;

	// required work in minutes
	int required_work_minutes = 480;

	while( record_count < MAX_RECORDS &&
			fscanf( file, " %[^,],%[^,],%d:%d,%d:%d", records[ record_count ].employee_id,
			records[ record_count ].date, &records[ record_count ].time_in.hour, &records[ record_count ].time_in.minute,
			&records[ record_count ].time_out.hour, &records[ record_count ].time_out.minute ) == 6 ){

			records[ record_count ].tardiness_minutes = calculate_tardiness( records[ record_count ].time_in );
			records[ record_count ].total_work_minutes = calculate_total_work_minutes( records[ record_count ].time_in,
                records[ record_count ].time_out );
            records[ record_count ].undertime_minutes = calculate_undertime_minutes( required_work_minutes,
                records[ record_count ].total_work_minutes );
            display_record( &records[ record_count ], record_count );
            record_count++;
    }

    fclose( file );
    *count = record_count;
    return records;
}

int main(){
    int record_count = 0;
    printf( "---LOADING RECORDS FROM FILE---\n");
    DailyRecord * records = load_records( &record_count );

    if( record_count > 0 ){
        printf( "Successfully loaded %d records.\n", record_count );
    }else{
        printf( "No records loaded.\n" );
    }

    free( records );
    return 0;
}

