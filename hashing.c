#include<stdio.h>
void main()
{
	int htable[30];
	int i, key, n, n2, index, j;
	printf("Enter how many elements: ");
	scanf("%d", &n);
	printf("Enter size of hash table: ");
	scanf("%d", &n2);
	
	for(i=0; i<n2; i++)
		htable[i] = 0;
	
	for(i=0; i<n; i++)
	{
		printf("Enter element %d:", (i+1));
		scanf("%d", &key);
		index = key%n2;
		j=1;
		while(htable[index]!=0 && j<n2)
		{
			index = (index+1*j+3*j*j) % n2;
			j++;
		}
		htable[index] = key;
	}
	for(i=0; i<n2; i++)
		printf("%d, ", htable[i]);
}
