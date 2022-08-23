#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};
struct Node *ar[20];	
typedef struct Node node;
void display(node *head)
{
    node *loc=head; 
    while(loc!=NULL)
    {
        printf("%d   ", loc->data);
        loc=loc->next;
    }
}
void insert_At_End(node **head, int item)
{
    node *temp,*loc;
    temp=(node*)malloc(sizeof(node));
    temp->data=item;
    temp->next= NULL;
    
    if(*head==NULL)
       *head=temp;
    else
    {
        loc=*head;
        while(loc->next!=NULL)
            loc=loc->next;
        loc->next=temp;
    }
}
void main()
{
	int i,m,index,value;
	int f=0;
	printf("Enter size of hash table: ");
	scanf("%d", &m);
	for(i=0;i<m;i++)
	{
		ar[i]=NULL;
	}
	for(i=0;i<m;i++)
	{
		printf("Enter a value:");
		scanf("%d", &value);
		index= value%m;
		insert_At_End(&ar[index], value);
		printf("\nenter 1 to continue....0 to stop: ");
		scanf("%d",&f);
		if(f==0)
			break;
	}
	for(i=0;i<m;i++)
	{
		if(ar[i]!=NULL)
		{
			display(ar[i]);
			printf("\n");
		}
		else
			printf("--\n");			
	}
}
