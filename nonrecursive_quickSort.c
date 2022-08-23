#include<stdio.h>

int top=-1;
static int b[50];
void push(int x)
{
	top++;
	b[top]=x;
}
int pop()
{
	return b[top--];
}
int quicksort(float a[], int lb, int ub)
{
	int i,j, pivot=lb;
	float temp;
	for(i=lb,j=ub;i<j;)
	{
		while(a[pivot]>a[i])
			i++;
		while(a[pivot]<a[j])
			j--;
		if(a[pivot]<=a[i] && a[pivot]>=a[j] && i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	if(lb!=j && a[pivot]>a[j])
	{
		temp=a[pivot];
		a[pivot]=a[j];
		a[j]=temp;
	}
	return j;
}
void stack(float ar[], int lb, int ub)
{
	int p,i;
	push(ub);
	push(lb);
	while(top!=-1)
	{
		lb=pop();
		ub=pop();
		p=quicksort(ar, lb, ub);
		if(p+1<ub)      //right sub-array
		{
			push(ub);
			push(p+1);
		}
		if(lb<p-1)    //left sub-array
		{
			push(p-1);
			push(lb);
		}
	}
}
void main()
{
	int i,n;
	float a[50];
	printf("Enter size of array:\n");
	scanf("%d",&n);
	printf("Enter array elements:\n");
	for(i=0;i<n;i++)
		scanf("%f",(a+i));
	printf("\nOriginal array:\n");
	for(i=0;i<n;i++)
		printf("%f ",a[i]);
	stack(a, 0,(n-1));
	printf("\nThe sorted array: \n");
	for(i=0;i<n;i++)
		printf("%f ",a[i]);
}
