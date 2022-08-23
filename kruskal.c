#include<stdio.h>
#define MAX 25
int findmin(int edge[MAX], int n)
{
	int m=999, i, index=0;
	for(i=0; i<n; i++)
		if(edge[i]!=0 && edge[i]<m)
		{
			m=edge[i];
			index=i;
		}
	return index;
}
void kruskal(int edges[MAX], int m, int n, int vertices[MAX])
{
	int i, j, a, b, p, flag=1, min=999, x, count, cost, mst[MAX], status[MAX];
	//initializing all arrays
	for(i=0; i<MAX; i++)
	{
		mst[i]=0;
		status[i+1]=i+1;
	}
	x=cost=count=0;
	//printing minimum spanning tree
	printf("\nMinimum cost spanning tree edges:");
	printf("\nSource\tEnd\tWeight");
	while(flag==1)
	{
		p=findmin(edges, m);
		flag=0;
		a=vertices[p]/10;
		b=vertices[p]%10;
		if(status[a]==status[b])
			edges[p]=vertices[p]=0;
		else
		{
			mst[x]=vertices[p];
			printf("\n%d\t%d\t%d", a, b, edges[p]);
			cost+=edges[p];
			edges[p]=vertices[p]=0;
			if(status[a]<status[b])	
			{
				j=status[b];
				status[b]=status[a];	
			}
			else
			{
				j=status[a];
				status[a]=status[b];
			}	
			for(i=1; i<=n; i++)
			{
				if(status[i]==j)
					status[i]=status[a];
			}
		}
		for(i=1; i<=n; i++)
		{
			if(status[i]!=1)
				flag=1;
		}
		p=0;
	}
	printf("\nCost: %d", cost);
}
void main()
{
	int edges[MAX], n, i, m, vertex[MAX];
	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	printf("Enter no. of edges: ");
	scanf("%d", &m);
	printf("\nEnter edge-weights and corresponding vertices:\n");
	for(i=0; i<m; i++)
	{
		printf("Enter edge-weight: ");
		scanf("%d", &edges[i]);
		printf("Enter vertices: ");
		scanf("%d", &vertex[i]);
	}
	kruskal(edges, m, n, vertex);
}
