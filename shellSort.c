#include<stdio.h>
#include<stdlib.h>
void shellSort(float ar[], int n)
{
	int i,j,interval=1,pass=1;
	float temp;
	while(interval<n/3)
		interval=interval*3+1;
	for( ; interval>0; interval/=3, pass++)
	{
		for(i=interval;i<n;i++)
		{
			for(j=i, temp=ar[i]; j>interval-1 && ar[j-interval]>temp; j-=interval)	
				ar[j]=ar[j-interval];
			ar[j]=temp;
		}
		printf("\npass%d\n", pass);
		for(i=0; i<n; i++)
			printf("%.3f\t", ar[i]);
	}
}
void main()
{
	float ar[20];
	int i,n;
	printf("Enter the size of array: ");
	scanf("%d", &n);
	for(i=0; i<n;i++)
	{
		printf("Enter the %d element:", (i+1));
		scanf("%f", (ar+i));
	}
	printf("\nBefore Sorting\n");
	for(i=0; i<n;i++)
		printf("%.3f, ", ar[i]);
	shellSort(ar, n);
	printf("\nAfter Sorting\n");
	for(i=0; i<n; i++)
		printf("%.3f, ", ar[i]);
}
