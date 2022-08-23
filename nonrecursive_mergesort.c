#include<stdio.h>
void merge(float a[], int lb, int mid, int ub)
{
    int i, j=mid+1, k=lb;
    float b[100];
    for(i=lb; i<=mid && j<=ub; k++)
    {
        if(a[i]>=a[j])
        {
            b[k]=a[j];
            j++;
        }
        else
        {
            b[k]=a[i];
            i++;
        }
    }
    while(j<=ub)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    while(i<=mid)
    {
        b[k]=a[i];
        i++;
        k++;
    }
    for(k=lb;k<=ub;k++)
        a[k]=b[k];
}
void merge_sort_nrec(float a[], int ub)
{
    int i,j,k,mid;
    for(k=1; k<=ub; k=2*k)
    {
		for(i=0; i<ub; i=i+2*k)
        {
            mid=i+k-1;
            if((i+2*k-1)<ub)
                j=(i+2*k-1);
            else
                j=ub;
            merge(a, i, mid, j);
        }
  	}
}
void main()
{
    int n,i;
    float a[50];
    printf("Enter number of elements:");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0; i<n; i++)
        scanf("%f",&a[i]);
    printf("\n\nGiven array is:\n");
    for(i=0; i<n; i++)
        printf("%f\t",a[i]);
    merge_sort_nrec(a,n-1);
    printf("\n\nThe sorted array is:\n");
    for(i=0; i<n; i++)
        printf("%f\t",a[i]);
}
