 //WAP to create a Binary tree and perform non-recursive Preorder, Inorder and Postorder traversal on it.

#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the binary tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


void preorder_nonrecursive(Node *root);
void inorder_nonrecursive(Node *root);
void postorder_nonrecursive(Node *root);

 
// Function to insert a node in the binary tree
struct Node* insertNode(struct Node* root, int value) 
{
    if (root == NULL) 
	{
        // If tree is empty, return a new node
        return createNode(value);
    }

    // Insert data based on its value
    if (value < root->data) 
	{
        root->left = insertNode(root->left, value);
    } 
	else 
	{
        root->right = insertNode(root->right, value);
    }
    
    return root;
}

int main() 
{
    int n, value, i;
    struct Node* root = NULL;

    // Ask user to define the number of nodes
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);

    // Insert each node
    for (i = 0; i < n; i++) 
	{
        printf("Enter the value for node %d: ", i+1);
        scanf("%d", &value);
        root = insertNode(root, value);
    }

    // Print the tree pre-order (root-left-right)
    printf("Preorder Traversal of the Binary Tree: ");
    preorder_nonrecursive(root);
    
    // Print the tree in-order (left-root-right)
    printf("Inorder Traversal of the Binary Tree: ");
    inorder_nonrecursive(root);
    
    // Print the tree post-order (left-root-right)
    printf("Postorder Traversal of the Binary Tree: ");
    postorder_nonrecursive(root);
    return 0;
}

void inorder_nonrecursive(Node *root)
{
	struct Node *stack[20]; int top=-1;
	while(root!=NULL||top!=-1)
	{
		if(root!=NULL)
		{
			stack[++top]=root; root=root->left;
		}
		else
		{
			root=stack[top--]; 
			printf("\t%d",root->data); 
			
			root=root->right;
		}
	}
}


void preorder_nonrecursive(Node *root)
{
	struct Node *stack[20];
	
	int top=-1; 
	
	stack[++top]=root; 
	
	while(top!=-1)
	{
		root=stack[top--]; 
		if(root!=NULL)
		{
			printf("\t%d",root->data); 
			stack[++top]=root->right; 
			stack[++top]=root->left;
		}
	}
}

void postorder_nonrecursive(Node *root)
 
{
	struct Node *stack[20]; int top=-1;
	int flag[10];
	while(top!=-1||root!=NULL)
		{
			if(root!=NULL)
			{
				stack[++top]=root; flag[top]=0; root=root->left;
			}
			else 
			{
				root=stack[top]; if(flag[top]==1)
				
	
					printf("\t%d",root->data); 
					top--;
					root=NULL;
			}
			else
			{
				flag[top]=1; root=root->right;
			}
		}
	
}

