#include <stdio.h>
#define MAX 25
void floyd( int ar[ MAX ][ MAX ], int n )
{
	int i, j, k, copy[ MAX ][ MAX ];
	for( i= 0; i < n; i++ )
	{
		for( j= 0; j < n; j++ )
			copy[ i ][ j ]= ar[ i ][ j ];
	}
	//performing floyd's technique
	for( k= 0; k < n; k++ )
	{
		for( i= 0; i < n; i++ )
		{
			for( j= 0; j < n; j++ )
			{
				if( copy[ i ][ j ] > copy[ k ][ j ] + copy[ i ][ k ] )
					copy[ i ][ j ] = copy[ k ][ j ] + copy[ i ][ k ];
			}
		}
		printf( "\nStep %d:\n", k+1 );
		for( i= 0; i < n; i++ )
		{
			for( j= 0; j < n; j++ )
				printf( "%d\t", copy[ i ][ j ] );
			printf( "\n" );
		}
	}
	//printing resultant matrix
	printf( "\nResultant matrix:\n" );
	for( i= 0; i < n; i++ )
	{
		for( j= 0; j < n; j++ )
			printf( "%d\t", copy[ i ][ j ] );
		printf( "\n" );
	}
}
void main( )
{
	int ar[ MAX ][ MAX ], n, i, j;
	printf( "Enter no. of vertices: " );
	scanf( "%d", &n );
	printf( "Enter Adjacency matrix:\n" );
	for( i= 0; i < n; i++ )
		for( j= 0; j < n; j++ )
			scanf( "%d", &ar[ i ][ j ] );
	//printing adjacency matrix
	printf( "Adjacency matrix:\n" );
	for( i= 0; i < n; i++ )
	{
		for( j= 0; j < n; j++ )
			printf( "%d\t", ar[ i ][ j ] );
		printf( "\n" );
	}
	floyd( ar, n );
}
