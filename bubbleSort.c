#include<stdio.h>
#include<stdlib.h>

struct llist
{
    	float data;
    	struct llist *next;
};
typedef struct llist node;
void insert_At_End(node **head, float item)
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
void sort(node *head)
{
    node *loc,*ptr;
    float temp;
    if(head==NULL)
    {
        printf("\nList is empty!");
        return;
    }
    loc=head; ptr=head;
    while(loc!=NULL)
    {
        //prev=prev->next;
        while((ptr!=NULL) && (ptr->next!=NULL))
		{
				if(ptr->data > ptr->next->data)
				{
                    temp=ptr->data;
					ptr->data=ptr->next->data;
					ptr->next->data=temp;
				}
				ptr=ptr->next;
		}
        loc=loc->next; ptr=head;
    }
}
void display(node *head)
{
    node *loc;
    if(head==NULL)
    {
        printf("List is empty!!");
        return;
    }
    loc=head;
    while(loc!=NULL)
    {
        printf("%f, ", loc->data);
        loc=loc->next;
    }
}
void main()
{
    int choice;
    float value;
    node *head;
    head=NULL;
    do
    {
        printf("\nEnter 1 to insert");
        printf("\nEnter 2 to sort");
        printf("\nEnter 3 to display");
        printf("\nEnter 4 to exit");
        printf("\nEnter your choice:");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1: printf("\nEnter data:");
                    scanf("%f", &value);
                    insert_At_End(&head, value);
                    fflush(stdin);
                    break;
            case 2: sort(head);
                    break;
            case 3: display(head);
                    break;
            case 4: exit(0);
                    break;
            default: printf("\nInvalid choice");
        }
    }while(choice!=4);
}
