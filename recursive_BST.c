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
	if(root!=NULL)
	{
        printf("%d\t",root->data);
        pretraversal(root->left);
		pretraversal(root->right);
	}
}
void intraversal(bst *root)       //in-order traversal
{
	if(root!=NULL)
	{
		intraversal(root->left);
		printf("%d\t",root->data);
		intraversal(root->right);
	}
}
void posttraversal(bst *root)     //post-order traversal
{
	if(root!=NULL)
	{
		posttraversal(root->left);
		posttraversal(root->right);
		printf("%d\t",root->data);
	}
}
bst* newnode()
{
	bst *node;
	node=(bst*)malloc(sizeof(bst));
	node->left=NULL;
	node->right=NULL;
	return node;
}
bst* create_bst(bst *root, int key)     //creating the tree
{
    if(root==NULL)
	{
        root=newnode();
		root->data=key;
	}
	else
	{
		if(root->data > key)
			root->left=create_bst(root->left, key);
		else if(root->data < key)
			root->right=create_bst(root->right, key);
	}
	return root;
}
void delete(bst **root, int key)       //deleting a node from tree
{
    bst *node;
    if(*root==NULL)
    {
       printf("Data not found!");
       return;
    }
    if( (*root)->data > key)
        delete(&((*root)->left), key);
    else if( (*root)->data < key)
        delete(&((*root)->right), key);
    else
    {   //if the node has both left and right child
        if( (*root)->left!=NULL && (*root)->right!=NULL)
        {
            node=(*root)->left;
            while(node->right!=NULL)    //finding in-order predecessor
                node=node->right;
            (*root)->data=node->data;
            delete(&((*root)->left), node->data);
        }
        else
        {   //if it is a terminal node
            node=*root;
            if((*root)->left!=NULL && (*root)->right==NULL)   //only left child
                *root=(*root)->left;
            else if((*root)->left==NULL && (*root)->right!=NULL)  //only right child
                *root=(*root)->right;
            else                        //leaf node
                *root=NULL;
            free(node);
        }
    }
}
int height(bst *root)      //height of tree
{
    int lheight, rheight;
    if(root==NULL)
        return 0;
    lheight=height(root->left);
    rheight=height(root->right);
    if(lheight>rheight)
       return ++lheight;
    else
       return ++rheight;
}
void searchnode(bst *root, int key)    //searching a node
{
	if(root!=NULL)
	{
		if(root->data>key)
			searchnode(root->left,key);
		else if(root->data<key)
			searchnode(root->right, key);
		else
			printf("\nData found.\n");
	}
	else if(root==NULL)
		printf("\nData not found.\n");
}
void mirrorimage(bst *root)     //creating a mirror image
{
	bst *temp;
	if(root!=NULL)
	{
		mirrorimage(root->left);
		mirrorimage(root->right);
		if(root->left!=NULL || root->right!=NULL)    //if there is any child
		{
			temp=root->left;
			root->left=root->right;      //swapping left and right child
			root->right=temp;
		}
	}
}
int leafnodes(bst *root)     //counting leaf nodes
{
	if(root==NULL)
		return 0;
	else if(root->left==NULL && root->right==NULL)
		return 1;
	else
		return(leafnodes(root->left)+leafnodes(root->right));
}
int nonleafnodes(bst *root)     //counting non-leaf nodes
{
	if(root==NULL)
		return 0;
	else if(root->left==NULL && root->right==NULL)
		return 0;
	else
		return(nonleafnodes(root->left)+nonleafnodes(root->right)+1);
}
void leveltraversal(bst *root)    //level-wise traversal
{
	bst *q[20],*ptr;
	int front=-1, rear=-1;
	if(root!=NULL)
	{
	    q[++rear]=root;
		front=0;
	    while(front!=-1)
	    {
            ptr=q[front];
			if(front==rear)
			{
				front=-1;
				rear=-1;
			}
			else
				front++;
			if(ptr->left!=NULL)
			{
				q[++rear]=ptr->left;   //pushing left child
				if(front==-1)
					front++;
			}
			if(ptr->right!=NULL)
			{
				q[++rear]=ptr->right;    //pushing right child
				if(front==-1)
					front++;
			}
			printf("%d\t",ptr->data);
	    }
    }
}
void main()
{
	bst *root= NULL;
	int choice, key;
	while(1)
	{
		printf("\n1. Insert a node");
		printf("\n2. Remove a node");
		printf("\n3. Preorder Traversal");
		printf("\n4. Inorder Traversal");
		printf("\n5. Postorder Traversal");
		printf("\n6. Leaf-node count");
		printf("\n7. Non-leaf-node count");
		printf("\n8. Level-wise Traversal");
		printf("\n9. Search a node");
		printf("\n10. Height of tree");
		printf("\n11. Mirror Image (Perform at last)");
		printf("\n12. Exit");
		printf("\nYour Choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
		    case 1: printf("\nEnter a value : ");
                    scanf("%d", &key);
                    root=create_bst(root, key);
                    break;
            case 2: printf("\nEnter which value to be deleted : ");
                    scanf("%d", &key);
                    delete(&root, key);
                    break;
            case 3: printf("\nPreorder Traversal : \n");
	                pretraversal(root);
	                break;
            case 4: printf("\nInorder Traversal : \n");
	                intraversal(root);
	                break;
            case 5: printf("\nPostorder Traversal : \n");
	                posttraversal(root);
	                break;
            case 6: printf("\nNumber of leaf nodes : %d", leafnodes(root));
                    break;
            case 7: printf("\nNumber of non-leaf nodes : %d", nonleafnodes(root));
                    break;
            case 8: printf("\nLevel-wise Traversal : \n");
	                leveltraversal(root);
	                break;
            case 9: printf("\nEnter the node value : ");
                    scanf("%d",&key);
                    searchnode(root, key);
	                break;
            case 10: printf("\nHeight of the tree : %d", height(root));
                     break;
            case 11: mirrorimage(root);
	                printf("\nInorder Travarsal of mirror image : \n");
                    intraversal(root);
                    break;
            case 12: exit(0);
            default: printf("Invalid Choice!");
        }
	}
}
