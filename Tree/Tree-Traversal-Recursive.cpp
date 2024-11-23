#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the binary tree
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the binary tree
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL) {
        // If tree is empty, return a new node
        return createNode(value);
    }

    // Insert data based on its value
    if (value < root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    
    return root;
}

// In-order traversal to print the binary tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
// Pre-order traversal to print the binary tree
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
    	 printf("%d ", root->data);
        preorderTraversal(root->left);
       
        preorderTraversal(root->right);
    }
}
//Post-order traversal to print the binary tree
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);   // 1. Traverse the left subtree
        postorderTraversal(root->right);  // 2. Traverse the right subtree
        printf("%d ", root->data);        // 3. Visit the root node
    }
}




int main() {
    int n, value, i,ch;
    struct Node* root = NULL;

    // Ask user to define the number of nodes
    printf("Enter the number of nodes in the binary tree: ");
    scanf("%d", &n);

    // Insert each node
    for (i = 0; i < n; i++) {
        printf("Enter the value for node %d: ", i+1);
        scanf("%d", &value);
        root = insertNode(root, value);
    }
    printf("\n1.Preorder\t2.Inorder\t3.Postorder");
    while(1)
    {
	
    
    printf("\nEnter choice : ");
    scanf("%d",&ch);
    
 switch (ch)
 {
 	case 1:
 			// Print the tree pre-order (left-root-right)
    printf("Preorder Traversal of the Binary Tree: ");
    preorderTraversal(root);
 		break;
 		
 	case 2 :
 		// Print the tree in-order (left-root-right)
    printf("Inorder Traversal of the Binary Tree: ");
    inorderTraversal(root);
    break;
    
    case 3 :
    		// Print the tree post-order (left-root-right)
    printf("Postorder Traversal of the Binary Tree: ");
    postorderTraversal(root);
    	break;
    case 4: exit(0);
    
 }
}
    
    return 0;
}

