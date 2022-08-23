#include<stdio.h>
void RadixSort(int ar[], int pass, int n, int div, int digCount)
{
    if(pass<=digCount)
    {
        int bucket[n], bCount[10], i, j, digit, k=0;
        for(i=0; i<10; i++)
           bCount[i]=0;
        for(i=0; i<n; i++)
           bucket[i]=0;
        for(i=0; i<n; i++)
        {
            digit=(ar[i]/div)%10;
            bCount[digit]++;
        }
        for(i=0; i<10; i++)
        {
            while(bCount[i]>0)
            {
                for(j=0; j<n; j++)
                {
                    if(((ar[j]/div)%10)==i)
                    {
                        bucket[k++]=ar[j];
                        bCount[i]--;
                    }
                }
            }
        }
        for(i=0; i<n; i++)
            ar[i]=bucket[i];
        printf("\nAfter pass %d: ", pass);
        for(i=0; i<n; i++)
            printf("%d, ", ar[i]);
        div=div*10;
        RadixSort(ar, pass+1, n, div, digCount);
    }
}
void main()
{
    int n, ar[50], i, max=0, pass=0, div=1, digCount=0;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("\nEnter only positive integers\n");
    for(i=0; i<n; i++)
    {
        printf("Enter element %d: ", (i+1));
        scanf("%d", (ar+i));
        if(ar[i]<0)
        {
            printf("Wrong input");
            exit(0);
        }
        if(ar[i]>max)
            max=ar[i];
    }
    while(max>0)
    {
        digCount++;
        max=max/10;
    }
    printf("\nOriginal array: ");
    for(i=0; i<n; i++)
        printf("%d, ", ar[i]);
        
    RadixSort(ar, 1, n, div, digCount);
    
    printf("\nAfter sorting: ");
        for(i=0; i<n; i++)
            printf("%d, ", ar[i]);
}
