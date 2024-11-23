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

int main() {
    int n, value, i,no;
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
      
      //insertion of new node
      printf("Enter A value for insertion :");
      scanf("%d",&no);
      root=insertNode(root,no);
      
      
    // Print the tree in-order (left-root-right)
    printf("Inorder Traversal of the Binary Tree: ");
    inorderTraversal(root);
    
    
    return 0;
}

