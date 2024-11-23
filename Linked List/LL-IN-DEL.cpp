#include <stdio.h>
#include <stdlib.h> 

typedef struct node {
    int data;
    struct node *next;
} node;

node *create(int n);
void print(node*);
int count(node *p);
void deleteNode(node **head_ref, int key);

node *create(int n) {
    node *p, *head;
    int i;

    head = (node*)malloc(sizeof(node));
    if (head == NULL) {
        printf("Memory allocation failed!\n");
        return NULL; 
    }

    printf("Enter data for node 1: ");
    scanf("%d", &(head->data));
    head->next = NULL;

    p = head;
    for (i = 1; i < n; i++) {
        p->next = (node*)malloc(sizeof(node));
        if (p->next == NULL) {
            printf("Memory allocation failed!\n");
            return NULL; 
        }

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &(p->next->data));
        p->next->next = NULL;
        p = p->next;
    }
    return head;
}

void print(node *p) {
    while (p != NULL) {
        printf("%d ", p->data); 
        p = p->next;
    }
    printf("\n"); 
}

int count(node *p) {
    int i = 0;
    while (p != NULL) { 
        p = p->next;
        i++;
    }
    return i;
}

void deleteNode(node **head_ref, int key) {
    node *temp = *head_ref, *prev = NULL;

    
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; 
        free(temp); 
        return;
    }

    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    
    if (temp == NULL) {
        printf("Node with value %d not found.\n", key);
        return;
    }

    
    prev->next = temp->next;
    
    free(temp); // Free memory
}

int main() {
    node *head;
    int n, x, valueToDelete;

    printf("Enter number of nodes: \n");
    scanf("%d", &n);

    head = create(n);
    
    if (head != NULL) { 
        print(head);
        
        x = count(head);
        printf("Number of Nodes: %d\n", x); 

        // Deletion 
        printf("Enter value to delete: ");
        scanf("%d", &valueToDelete);
        
        deleteNode(&head, valueToDelete);
        
        printf("Updated List after deletion:\n");
        print(head);

        x = count(head);
        printf("Number of Nodes after deletion: %d\n", x); 
    }

    

    return 0;
}
