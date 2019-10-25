#include<stdio.h>
#include<stdlib.h>
struct node 
{
int data;
struct node *left;
struct node *right;
};

struct node *root=NULL;

int menu()
{
int no;
printf("\n1.Create ");
printf("\n2.Traverse preorder");
printf("\n3.Traverse inorder");
printf("\n4.Traverse postorder");
printf("\n5.Exit");
printf("\n\nEnter your choice: ");
scanf("%d",&no);
return no;
}

struct node* createNode()
{
struct node *n;
n=(struct node*)malloc(sizeof(struct node));
n->left=NULL;
n->right=NULL;
return n;
}
void create(int item)
{
struct node *temp,*p,*c;
temp=createNode();
temp->data=item;

if (root==NULL)
{
	root=temp;
}
else
{
	p=NULL;
	c=root;
	while(c!=NULL)
	{
	p=c;
	if(temp->data<c->data)
	c=c->left;
	else
	c=c->right;
	}

if(temp->data<p->data)
p->left=temp;
else
p->right=temp;

}
}



void preorder(struct node *root)
{
if(root)
{
	printf("%d ",root->data);
	preorder(root->left);
	preorder(root->right);
}
}


void inorder(struct node *root)
{
if(root)
{
	inorder(root->left);
	printf("%d ",root->data);
	inorder(root->right);
}
}


void postorder(struct node *root)
{
if(root)
{
	postorder(root->left);
	postorder(root->right);
	printf("%d ",root->data);
}
}



int main()
{
int x;
while(1)
{
	switch(menu())
	{
	     case 1: printf("\nEnter item : ");
	             scanf("%d",&x);
	             create(x);
	             break;		  
	    
	     case 2: preorder(root);break;
	     
	     case 3:inorder(root);break;
	     
	     case 4:postorder(root);break;
	     
	 
	     
	     case 5:exit(0);
	
	}

}
return 0;
}

