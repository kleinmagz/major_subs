#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person{
	int nid;
	char fullname[ 100 ];
}CIT;

int main(){
	
	CIT p;
	CIT * ptr = NULL;
	CIT pr[ 10 ];

	p.nid = 1000123;
	strcpy( p.fullname, "Ralph Tajantajan" );
	
	printf( "ID: %d\nName: %s", p.nid, p.fullname );
	
	pr[ 0 ].nid = 1000456;
	strcpy( pr[ 0 ].fullname, "Mark Pelong" );
	printf( "\n\nID: %d\nName: %s", pr[ 0 ].nid, pr[ 0 ].fullname );

	ptr = &p;
	printf( "\n\nID: %d\nName: %s", ptr->nid, ptr->fullname );

	ptr = &pr[ 1 ];
	ptr->nid = 1000987;
	strcpy( ptr->fullname,"Klein Magallano" );
	//printf( "\n\nid: %d\nname: %s", pr[ 1 ].nid, pr[ 1 ].fullname );
	printf( "\n\nid: %d\nname: %s", pr[ 1 ].nid, pr[ 1 ].fullname );
	
	printf( "\n=== DMA demonstration ===\n" );

	// DMA demonstration
	int i, n;
	printf( "Actual N: " );
	scanf( "%d", &n );
	ptr = ( CIT * )malloc( n * sizeof( CIT ) );

	if( ptr == NULL ){
		printf( "Error: Allocation failed. Program is terminating..." );
		return 0;
	}

	// Populates the array
	for( i = 0; i < n; i++ ){
		printf( "\nSet %d\n\t", i + 1 );
		printf( "NID: " );
		scanf( "%d", &( ptr + i )->nid );	//also valid: &ptr[i].nid
		printf( "\tName: " );
		getchar();
		//fflush( stdin );
		fgets( ( ptr + i )->fullname, 100, stdin );
		fflush( stdin );			// clears the input stream
	}

	// Displays the info
	for( i = 0; i < n; i++ ){
		printf( "\nRecord Set %d\n\t", i + 1 );
		printf( "NID: %d", ptr[ i ].nid );
		printf( "\tName: %s", ptr[ i ].fullname );
	}
	
	free( ptr );

	printf( "\n" );
	return 0;
}
