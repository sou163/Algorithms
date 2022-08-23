#include<stdio.h>
#include<stdlib.h>
struct btree
{
	int data;
	struct btree *left, *right;
};
typedef struct btree tree;
tree* create(tree *root)
{
	int choice=0;
	if(root==NULL)
	{
		root=(tree*)malloc(sizeof(tree));
		printf("\nEnter value:");
		scanf("%d", &(root->data));
		root->left=root->right=NULL;
	}
	printf("\nCurrent node data:%d",root->data);
	printf("\nWant a left child? 1 for yes ...0 for no: ");
	scanf("%d", &choice);
	if(choice==1)
		root->left=create(root->left);
	choice=0;
	printf("\nCurrent node data:%d",root->data);
	printf("\nWant a right child? 1 for yes ...0 for no: ");
	scanf("%d", &choice);
	if(choice==1)
		root->right=create(root->right);
	return root;
}
void inordertraversal(tree *root)
{
	if(root!=NULL)
	{
		inordertraversal(root->left);
		printf("%d ", root->data);
		inordertraversal(root->right);
	}
}
void preordertraversal(tree *root)
{
	if(root!=NULL)
	{
		printf("%d ", root->data);
		preordertraversal(root->left);
		preordertraversal(root->right);
	}
}
void postordertraversal(tree *root)
{
	if(root!=NULL)
	{
		postordertraversal(root->left);
		postordertraversal(root->right);
		printf("%d ", root->data);
	}
}
void main()
{
	tree *root=NULL;
	int choice;
	while(choice!=5)
	{
		printf("\nEnter 1 to insertion");
		printf("\nEnter 2 to inorder traversal");
		printf("\nEnter 3 to preorder traversal");
		printf("\nEnter 4 to postorder traversal");
		printf("\nEnter 5 to exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: root=create(root);
			        break;
			case 2: inordertraversal(root);
			        break;
			case 3: preordertraversal(root);
			        break;
			case 4: postordertraversal(root);
			        break;
			case 5: exit(0);
			default:printf("Invalid choice");
		}
	}
}
