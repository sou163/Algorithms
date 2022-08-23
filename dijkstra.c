#include<stdio.h>
#define MAX 25
int findmin(int edges[MAX], int n)
{
	int m=999, i, index=0;
	for(i=0; i<n; i++)
		if(edges[i]!=0 && edges[i]<m)
		{
			m=edges[i];
			index=i;
		}
	return index;
}
void dijkstra(int ar[MAX][MAX], int n)
{
	int edge[MAX], vertices[MAX], mst[MAX], visited[MAX], weight[MAX];
	int i, j, a, b, k, p, f1, f2, min=999, x, count=1, cost, sum, start;
	//initializing all arrays
	for(i=0; i<MAX; i++)
		edge[i]=vertices[i]=mst[i]=visited[i]=weight[i]=0;
	printf("\nEnter starting vertex: ");
	scanf("%d", &i);	start=i;
	visited[i]=1;
	k=x=f1=f2=cost=sum=0;
	while(count!=n)
	{
		for(j=0; j<n; j++)
		{
			if(ar[i][j]!=0)
			{
				for(p=0; p<k; p++)
					if(mst[p]==(i*10+j))
					{
						f1=1;
						break;
					}
				for(p=0; p<k && f1==0; p++)
					if(vertices[p]==(i*10+j))
					{
						f2=1;
						break;
					}
				if(f1==0 && f2==0)
				{
					edge[k]=ar[i][j];
					vertices[k++]=i*10+j;
					if( j != start )	//storing the minimum cost to each vertex
					{
						cost= sum + ar[ i ][ j ];
						if( weight[ j ] == 0 )
							weight[ j ]= cost;
						else if( cost < weight[ j ] )
							weight[ j ]= cost;
					}
				}
			}
		}
		do
		{
			p=findmin(edge, k);
			a=vertices[p]/10;
			b=vertices[p]%10;
			if(visited[a]==1 && visited[b]==1)
			{
				edge[p]=vertices[p]=0;
			}
			else
			{
				min=edge[p];
				mst[x++]=vertices[p];
				printf("\n %d -- > %d", a, b);
				if(visited[a]==0)
					i=a; 
				else
					i=b;
				visited[a]=visited[b]=1;	count+=1;
				sum=edge[p]+weight[a];
				edge[p]=vertices[p]=0;
			}
		}while(min==999);
		min=999;	p=f1=f2=0;
	}
	printf( "\nMinimum cost traversals:" );
	for( j=0; j < n; j++ )
	{
		printf( "\n%d ---> %d: %d", start, j, weight[ j ] );
	}
	
}
void main()
{
	int ar[MAX][MAX], n, i, j;
	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	printf("Enter Adjacency matrix:\n");
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			scanf("%d", &ar[i][j]);
	//printing adjacency matrix
	printf("Adjacency matrix:\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%d\t", ar[i][j]);
		printf("\n");
	}
	dijkstra(ar, n);
}
