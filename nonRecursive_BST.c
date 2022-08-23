#include<stdio.h>
#include<stdlib.h>
struct Tree
{
	int data;
	struct Tree *left, *right;
};
typedef struct Tree bst;

void pretraversal(bst *root)    //pre-order traversal
{
    bst *ptr=root, *stack[20];
    int top=-1;
    while(ptr!=NULL)
    {
        printf("%d\t", ptr->data);
        if(ptr->right!=NULL)
            stack[++top]=ptr->right;
        if(ptr->left!=NULL)
            ptr=ptr->left;          //traversing left
        else
        {
            if(top==-1)
                ptr=NULL;
            else
                ptr=stack[top--];               //skipping to right
        }
    }
}
void intraversal(bst *root)       //in-order traversal
{
    bst *ptr=root, *stack[20];
    int top=-1, flag, done=0;
    while(!done)
    {
        while(ptr!=NULL)
        {
            stack[++top]=ptr;
            ptr=ptr->left;    //traversing left
        }
        ptr=stack[top--];
        flag=1;
        while(ptr!=NULL && flag==1)
        {
            printf("%d\t", ptr->data);
            if(ptr->right!=NULL)
            {
                ptr=ptr->right;   //skipping to right
                flag=0;
            }
            else
            {
                if(top==-1)
                    ptr=NULL;
                else
                    ptr=stack[top--];        //traversing back to parent node
            }
        }
        if(ptr==NULL)
            done=1;
    }
}
void posttraversal(bst *root)     //post-order traversal
{
    bst *ptr=root, *stack[20], *stack2[10];
    int top=-1, top2=-1, flag, flag2=1, done=0;
    while(!done)
    {
        while(ptr!=NULL)
        {
            stack[++top]=ptr;  
            ptr=ptr->left;              //traversing left
        }
        ptr=stack[top--]; 
        flag=1;
        while(ptr!=NULL && flag==1)
        {
            if(ptr->right!=NULL)   //if ptr is a non-leaf node
            {
                stack2[++top2]=ptr;              
                ptr=ptr->right;                  //skipping to right
                flag=0;
            }
            else
            {
                printf("%d\t", ptr->data);   //printing leaf nodes
                if(top==-1)
                    ptr=NULL;
                else
                    ptr=stack[top--];        //traversing back to parent node
            }
            if((ptr==root && flag2<3) || ptr==NULL)
            {
                flag2++;                 
                while(stack2[top2]!=root && top2!=-1)
                    printf("%d\t", (stack2[top2--])->data); //printing non-leaf nodes
            }
        }
        if(ptr==NULL)
            done=1;
    }
    printf("%d\t", (stack2[top2--])->data);    //printing root
}
void create_bst(bst **root, int key)     //creating the tree
{
    bst *node=*root, *temp, *loc=NULL;
    temp=(bst*)malloc(sizeof(bst));
    temp->data=key;
    temp->left=NULL;
    temp->right=NULL;

    while(node!=NULL)
    {
        loc=node;                  //searching for exact location to enter
        if(node->data > key)
            node=node->left;
        else if(node->data < key)
            node=node->right;
    }
    if(loc==NULL)            //if root is NULL
        *root=temp;
    else if(loc->data > key)
        loc->left=temp;
    else if(loc->data < key)
        loc->right=temp;
}
void main()
{
	bst *root=NULL;
	int choice, key, choice2=1;
	while(1)
	{
		printf("\n1. Insert a node");
		printf("\n2. Preorder Traversal");
		printf("\n3. Inorder Traversal");
		printf("\n4. Postorder Traversal");
		printf("\n5. Exit");
		printf("\nYour Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
		    case 1: while(choice2)
                    {
                        printf("\nEnter value: ");
                        scanf("%d", &key);
                        create_bst(&root, key);
                        printf("Do you want to enter again? Enter 1 for yes ...0 for no: ");
                        scanf("%d", &choice2);
                    }
                    break;
            case 2: printf("\nPreorder Traversal : \n");
	                pretraversal(root);
	                break;
            case 3: printf("\nInorder Traversal : \n");
	                intraversal(root);
	                break;
            case 4: printf("\nPostorder Traversal : \n");
	                posttraversal(root);
	                break;
            case 5: exit(0);
            default: printf("Invalid Choice!");
        }
	}
}
