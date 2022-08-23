#include<stdio.h>
#define MAX 25
int findmin(int edges[MAX], int n)
{
	int m = 999, i, index = 0;
	for(i=0; i < n; i++)
		if(edges[i] != 0 && edges[i] < m)
		{
			m = edges[i];
			index = i;
		}
	return index;
}
void prim(int ar[MAX][MAX], int n)
{
	int i, j, a, b, k, p, f1, f2, min = 999, x, count = 1, cost;
	int edges[MAX], vertices[MAX], mst[MAX], visited[MAX];
	//initializing all arrays
	for(i=0; i < MAX; i++)
		edges[i] = vertices[i] = mst[i] = visited[i] = 0;
	printf( "\nEnter starting vertex: " );
	scanf( "%d", &i );
	visited[i] = 1;
	k = x = f1 = f2 = cost = 0;
	//printing minimum spanning tree
	printf( "\nMinimum cost spanning tree edges:" );
	printf( "\nSource\tEnd\tWeight" );
	while(count != n)
	{
		for(j=0; j < n; j++)
		{
			if(ar[i][j] != 0)
			{
				for(p=0; p < k; p++)
					if(mst[p] == (i*10+j))
					{
						f1 = 1;
						break;
					}
				for(p=0; p < k  &&  f1 == 0; p++)
					if(vertices[p] == (i*10+j))
					{
						f2 = 1;
						break;
					}
				if(f1 == 0  &&  f2 == 0)
				{
					edges[k] = ar[i][j];		//extracting new edges into a separate array
					vertices[k++] = i*10+j;	
				}
			}
		}
		do
		{
			p = findmin(edges, k);
			a = vertices[p] / 10;
			b = vertices[p] % 10;
			if(visited[a] == 1  &&  visited[b] == 1)	//cycle checking clause
			{
				edges[p] = vertices[p] = 0;		//discarding edges forming cycles
			}
			else
			{
				min = edges[p];
				mst[x++] = vertices[p];
				printf( "\n%d\t%d\t%d", a, b, edges[p] );
				cost += edges[p];				//calculating the total weight of the min span tree
				edges[p] = vertices[p] = 0;
				if(visited[a] == 0)
					i = a;
				else
					i = b;
				visited[a] = visited[b] = 1;	count += 1;
			}
		}while(min == 999);
		min = 999;		p = f1 = f2 = 0;
	}
	printf( "\nCost: %d", cost );
}
void main()
{
	int ar[MAX][MAX], n, i, j;
	printf( "Enter no. of vertices: " );
	scanf( "%d", &n );
	printf( "Enter Adjacency matrix:\n" );
	for(i=0; i < n; i++)
		for(j=0; j < n; j++)
			scanf( "%d", &ar[i][j] );
	//printing adjacency matrix
	printf( "Adjacency matrix:\n" );
	for(i=0; i < n; i++)
	{
		for(j=0; j < n; j++)
			printf( "%d\t", ar[i][j] );
		printf( "\n" );
	}
	prim(ar, n);
}
