#include<stdio.h>
#include<stdlib.h>
void in_ascend(float ar[], int l)
{
	float temp;
	int pos, i, j;
	for(i=1;i<l;i++)
	{
		temp=ar[i]; pos=i;
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
	printf("After sorted : ");
	for(i=0;i<l;i++)
 		printf("%f, ", ar[i]);
}
void in_descend(float ar[], int l)
{
	float temp;
	int pos, i, j;
	for(i=1;i<l;i++)
	{
		temp=ar[i]; pos=i;
		for(j=i-1;j>=0;j--)
		{
			if(ar[j]<temp)
			{
				ar[j+1]=ar[j];
				pos=j;
			}
		}
		ar[pos]=temp;
	}
	printf("After sorted : ");
	for(i=0;i<l;i++)
		printf("%f, ", ar[i]);
}
void sel_ascend(float ar[], int l)
{
	float temp, small;
	int pos, i, j;
	for(i=0;i<l;i++)
	{
		small=ar[i];
		pos=i;
		for(j=i+1;j<l;j++)
		{
			if(ar[j]<small)
			{
				small=ar[j];
				pos=j;
			}
		}
		temp=ar[i];
		ar[i]=ar[pos];
		ar[pos]=temp;
	}
	printf("After sorted : ");
	for(i=0;i<l;i++)
 		printf("%f, ", ar[i]);
}
void sel_descend(float ar[], int l)
{
	float temp, small;
	int pos, i, j;
	for(i=0;i<l;i++)
	{
		small=ar[i];
		pos=i;
		for(j=i+1;j<l;j++)
		{
			if(ar[j]>small)
			{
				small=ar[j];
				pos=j;
			}
		}
		temp=ar[i];
		ar[i]=ar[pos];
		ar[pos]=temp;
	}
	printf("After sorted : ");
	for(i=0;i<l;i++)
 		printf("%f, ", ar[i]);
}
void main()
{
	int choice, size, i, choice2;
	float arr[100];
	printf("Enter size of array: ");
	scanf("%d", &size);
	do
	{
		printf("\nEnter 1 for insertion sort");
		printf("\nEnter 2 for selection sort");
		printf("\nEnter 3 to exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1: for(i=0;i<size;i++)
	                {
                        printf("Enter element %d: ", (i+1));
		                scanf("%f", (arr+i));
                    }
                    printf("\nEnter 1 to sort in ascending order");
		            printf("\nEnter 2 to sort in descending order");
		            printf("\nEnter your choice: ");
		            scanf("%d", &choice2);
		            switch(choice2)
		            {
                        case 1: in_ascend(arr, size);
					           break;
                        case 2: in_descend(arr,size);
					            break;
					    default: printf("\nInvalid choice!");
	                }
	                break;
	        case 2: for(i=0;i<size;i++)
	                {
                        printf("Enter element %d: ", (i+1));
		                scanf("%f", (arr+i));
                    }
                    printf("\nEnter 1 to sort in ascending order");
		            printf("\nEnter 2 to sort in descending order");
		            printf("\nEnter your choice: ");
		            scanf("%d", &choice2);
		            switch(choice2)
		            {
                        case 1: sel_ascend(arr, size);
					           break;
                        case 2: sel_descend(arr,size);
					            break;
					    default: printf("\nInvalid choice!");
	                }
	                break;
	        case 3: exit(0);
                    break;
            default: printf("\nInvalid choice!");
		}
	}while(choice!=3);
}
