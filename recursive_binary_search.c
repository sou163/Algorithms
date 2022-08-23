#include<stdio.h>
int binSearch(int a[], int item, int l, int u)
{
    int mid=(l+u)/2;
    if(l<=u)
    {
        if(a[mid]==item)
            return (mid+1);
        else if(a[mid]<item)
             return binSearch(a, item, mid+1, u);
        else if(a[mid]>item)
             return binSearch(a, item, l, mid-1);
    }
    return -1;
}
void main()
{
    int n,i,ar[50],j,temp,pos,search,f=-1;
    printf("Enter the size of array:");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        printf("Enter element %d:", (i+1));
        scanf("%d", (ar+i));
    }
    for(i=1;i<n;i++)
    {
        temp=ar[i];   pos=i;
        for(j=i-1;j>=0;j--)
        {
            if(ar[j]>temp)
            {
                ar[j+1]=ar[j];
                pos=j;
            }
        }
        ar[pos]=temp;
    }
    printf("\nEnter element to be searched:");
    scanf("%d", &search);
    f= binSearch(ar, search, 0, n-1);
    if(f==-1)
       printf("\nSearch element not found!");
    else
        printf("\nSearch element found at index: %d", f);
}
