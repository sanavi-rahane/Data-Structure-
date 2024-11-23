 #include <stdio.h> 
#include <stdlib.h> 
 
// Define a structure for a node 
struct Node { 
    int data; 
    struct Node* next; 
}; 
 
// Function to create a new node 
struct Node* createNode(int data) { 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); 
    newNode->data = data; 
    newNode->next = NULL; 
    return newNode; 
} 
 
// Function to insert a node at the beginning 
void insertAtBeginning(struct Node** head, int data) { 
    struct Node* newNode = createNode(data); 
    newNode->next = *head; 
    *head = newNode; 
} 
 
// Function to insert a node at the end 
void insertAtEnd(struct Node** head, int data) { 
    struct Node* newNode = createNode(data); 
    if (*head == NULL) { 
        *head = newNode; 
        return; 
    } 
    struct Node* temp = *head; 
    while (temp->next != NULL) { 
        temp = temp->next; 
    } 
    temp->next = newNode; 
} 
 
// Function to insert a node at a specific position 
void insertAtPosition(struct Node** head, int data, int position) { 
 int i; 
    struct Node* newNode = createNode(data); 
    if (position == 1) { 
        newNode->next = *head; 
        *head = newNode; 
        return; 
    } 
    struct Node* temp = *head; 
    for (i = 1; i < position - 1 && temp != NULL; i++) { 
        temp = temp->next; 
    } 
    if (temp == NULL) { 
        printf("Position out of range\n"); 
        free(newNode); 
        return; 
    } 
    newNode->next = temp->next; 
    temp->next = newNode; 
} 
 
// Function to delete a node from the beginning 
void deleteAtBeginning(struct Node** head) { 
    if (*head == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
    struct Node* temp = *head; 
    *head = (*head)->next; 
    free(temp); 
} 
 
// Function to delete a node from the end 
void deleteAtEnd(struct Node** head) { 
    if (*head == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
    struct Node* temp = *head; 
    if (temp->next == NULL) { // Only one node 
        free(temp); 
        *head = NULL; 
        return; 
    } 
    while (temp->next->next != NULL) { 
        temp = temp->next; 
    } 
    free(temp->next); 
    temp->next = NULL; 
} 
 
// Function to delete a node from a specific position 
void deleteAtPosition(struct Node** head, int position) { 
 int i; 
    if (*head == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
    struct Node* temp = *head; 
    if (position == 1) { 
        *head = temp->next; 
        free(temp); 
        return; 
    } 
    struct Node* prev = NULL; 
    for ( i = 1; i < position && temp != NULL; i++) { 
        prev = temp; 
        temp = temp->next; 
    } 
    if (temp == NULL) { 
        printf("Position out of range\n"); 
        return; 
    } 
    prev->next = temp->next; 
    free(temp); 
} 
 
// Function to display the linked list 
void displayList(struct Node* head) { 
    if (head == NULL) { 
        printf("List is empty\n"); 
        return; 
    } 
    struct Node* temp = head; 
    while (temp != NULL) { 
        printf("%d -> ", temp->data); 
        temp = temp->next; 
    } 
    printf("NULL\n"); 
} 
 
// Main function with menu 
int main() { 
    struct Node* head = NULL; 
    int choice, data, position; 
 
    while (1) { 
        printf("\nMenu:\n"); 
        printf("1. Insert at Beginning\n"); 
        printf("2. Insert at End\n"); 
        printf("3. Insert at Position\n"); 
        printf("4. Delete at Beginning\n"); 
        printf("5. Delete at End\n"); 
        printf("6. Delete at Position\n"); 
        printf("7. Display List\n"); 
        printf("8. Exit\n"); 
        printf("Enter your choice: "); 
        scanf("%d", &choice); 
 
        switch (choice) { 
            case 1: 
                printf("Enter data to insert at beginning: "); 
                scanf("%d", &data); 
                insertAtBeginning(&head, data); 
                break; 
            case 2: 
                printf("Enter data to insert at end: "); 
                scanf("%d", &data); 
                insertAtEnd(&head, data); 
                break; 
            case 3: 
                printf("Enter data to insert and position: "); 
                scanf("%d %d", &data, &position); 
                insertAtPosition(&head, data, position); 
                break; 
            case 4: 
                deleteAtBeginning(&head); 
                break; 
            case 5: 
                deleteAtEnd(&head); 
                break; 
            case 6: 
                printf("Enter position to delete: "); 
                scanf("%d", &position); 
                deleteAtPosition(&head, position); 
                break; 
            case 7: 
                displayList(head); 
                break; 
            case 8: 
                exit(0); 
            default: 
                printf("Invalid choice! Please try again.\n"); 
        } 
    } 
 
    return 0; 
} 
 