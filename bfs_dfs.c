//Bfs-Dfs Traversals
#include<stdio.h>
void bfs(int a[10][10], int n, int start)
{
	int visited[10], queue[10], front=-1, rear=-1, count=0, element, i, j;
	for(i=0; i<n; i++)
		visited[i]=0;
	printf("\nBFS Traversal: ");
	if(front==rear)
	{
		front++;
		queue[++rear]=start;
		visited[start-1]=1;		count=1;
		printf("%d, ", start);
	}
	//traversing
	while(count!=n)
	{
		element=queue[front++];
		i=element-1;
		for(j=0; j<n; j++)
		{
			if(a[i][j]==1 && visited[j]==0)
			{
				queue[++rear]=j+1;
				visited[j]=1;	count++;
				printf("%d, ", j+1);
			}
		}
	}
}

void dfs(int a[10][10], int n, int start)
{
	int visited[10], stack[10], top=-1, count=0, element, i, j, flag=1;
	for(i=0; i<n; i++)
		visited[i]=0;
	printf("\nDFS Traversal: ");
	if(top==-1)
	{
		stack[++top]=start;		i=start-1;
		visited[i]=1;		count=1;
		printf("%d, ", start);
	}
	//traversing
	while(count!=n)
	{
		if(flag==0)
		{
			element=stack[--top];
			i=element-1;
			flag=1;
		}
		for(j=0; j<n; j++)
		{
			if(a[i][j]==1 && visited[j]==0)
			{
				stack[++top]=j+1;	flag=1;
				visited[j]=1;	count++;
				printf("%d, ", j+1);
				i=j;
				break;
			}
			else
				flag=0;
		}
	}
}
void main()
{
	int ar[10][10], choice, n, i, j, check=0, start;
	printf("Enter no. of vertices: ");
	scanf("%d", &n);
	printf("Enter 1 for Bfs traversal..2 for Dfs traversal: ");
	scanf("%d", &choice);
	printf("Enter starting vertex: ");
	scanf("%d", &start);
	
	//adjacency matrix formation
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			ar[i][j]=0;
			printf("%d --> %d ? Enter 1 for yes..0 for no: ", i+1, j+1);
			scanf("%d", &check);
			if(check==1)
				ar[i][j]=1;
		}
		printf("\n");
	}
	
	//printing adjacency matrix
	printf("Adjacency matrix:\n");
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
			printf("%d\t", ar[i][j]);
		printf("\n");
	}
	
	if(choice==1)
		bfs(ar, n, start);
	else if(choice==2)
		dfs(ar, n, start);
	else
		printf("Wrong choice!!");
}
