#include<stdio.h>
#include<stdlib.h>
void Merge(float[], int, int, int);

void Qsort(float a[], int m, int n)
{
	int pivot,i,j;
	float temp;
	if(m<n)
	{
		pivot=m;
		i=m; j=n;
		while(i<j)
		{
			while(a[i]<a[pivot] && i<n)
				i=i+1;
			while(a[j]>a[pivot] && j>=m)
				j=j-1;
			if(i<j)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
		temp=a[m];
		a[m]=a[j];
		a[j]=temp;
		Qsort(a, m, j-1);
		Qsort(a, j+1, n); 
		     
	}                            
}	
void Msort(float a[], int m, int n)
{
	int mid;
	if(m<n)
	{
		mid=(m+n)/2;
		Msort(a, m, mid);
		Msort(a, mid+1, n);
		Merge(a, m, mid, n);
	}
	
}
void Merge(float a[], int m, int mid, int n)
{
	float b[20];
	int i,j,k;
	i=m; j=mid+1; k=m;
	while(i<=mid && j<=n)
	{
		if(a[i]<a[j])
		{
			b[k]=a[i];
			i++;
		}
		else
		{
			b[k]=a[j];
			j++;
		}
		k++;
	}
	while(i<=mid)
	{
		b[k]=a[i];
		i++;
		k++;
	}
	while(j<=n)
	{
		b[k]=a[j];
		j++;
		k++;
	}
	for(i=m; i<=n; i++)
	{
		a[i]=b[i];
	}
}
void main()
{
	int choice,n,i;
	float ar[50];
	do
	{
		printf("\n\nEnter 1 to quick sort");
		printf("\nEnter 2 to merge sort");
		printf("\nEnter 3 to exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: printf("Enter the size of array: ");
					scanf("%d", &n);
					for(i=0; i<n; i++)
					{
						printf("Enter element %d: ", (i+1));
						scanf("%f", (ar+i));
					}
					Qsort(ar,0, n-1);
					printf("\nQuick-sorted array: ");
					for(i=0; i<n; i++)
						printf("%f, ", ar[i]);
					break;
			case 2: printf("Enter the size of array: ");
					scanf("%d", &n);
					for(i=0; i<n; i++)
					{
						printf("Enter element %d: ", (i+1));
						scanf("%f", (ar+i));
					}
					Msort(ar, 0, n-1);
					printf("\nMerge-sorted array: ");
					for(i=0;i<n;i++)
						printf("%f, ", ar[i]);
				   	break;
			case 3: exit(0);
                    break;
            default: printf("Invalid choice!");
		}
	}while(choice!=3);
}		   	   	
