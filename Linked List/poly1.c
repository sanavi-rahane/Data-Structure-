#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the list
void insertNode(Node** head, int coeff, int exp) {
    Node* newNode = createNode(coeff, exp);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to display the polynomial
void displayPoly(Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->coeff);
        if (temp->exp != 0)
            printf("x^%d", temp->exp);
        if (temp->next != NULL)
            printf(" + ");
        temp = temp->next;
    }
    printf("\n");
}

// Function to add two polynomials
Node* addPoly(Node* poly1, Node* poly2) {
    Node* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exp > poly2->exp) {
            insertNode(&result, poly1->coeff, poly1->exp);
            poly1 = poly1->next;
        } else if (poly1->exp < poly2->exp) {
            insertNode(&result, poly2->coeff, poly2->exp);
            poly2 = poly2->next;
        } else {
            insertNode(&result, poly1->coeff + poly2->coeff, poly1->exp);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL) {
        insertNode(&result, poly1->coeff, poly1->exp);
        poly1 = poly1->next;
    }
    while (poly2 != NULL) {
        insertNode(&result, poly2->coeff, poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

// Function to multiply two polynomials
Node* multiplyPoly(Node* poly1, Node* poly2) {
    if (poly1 == NULL || poly2 == NULL)
        return NULL;
    
    Node* result = NULL;
    for (Node* ptr1 = poly1; ptr1 != NULL; ptr1 = ptr1->next) {
        for (Node* ptr2 = poly2; ptr2 != NULL; ptr2 = ptr2->next) {
            insertNode(&result, ptr1->coeff * ptr2->coeff, ptr1->exp + ptr2->exp);
        }
    }

    // Combine terms with the same exponent
    Node* temp = result;
    Node* prev = NULL;
    while (temp != NULL) {
        Node* inner = temp->next;
        prev = temp;
        while (inner != NULL) {
            if (temp->exp == inner->exp) {
                temp->coeff += inner->coeff;
                prev->next = inner->next;
                free(inner);
                inner = prev->next;
            } else {
                prev = inner;
                inner = inner->next;
            }
        }
        temp = temp->next;
    }
    return result;
}

int main() {
    Node* poly1 = NULL;
    Node* poly2 = NULL;

    // Example: Creating first polynomial 3x^2 + 5x + 6
    insertNode(&poly1, 3, 2);
    insertNode(&poly1, 5, 1);
    insertNode(&poly1, 6, 0);

    // Example: Creating second polynomial 6x^1 + 8
    insertNode(&poly2, 6, 1);
    insertNode(&poly2, 8, 0);

    printf("First Polynomial: ");
    displayPoly(poly1);

    printf("Second Polynomial: ");
    displayPoly(poly2);

    // Adding the two polynomials
    Node* sum = addPoly(poly1, poly2);
    printf("Sum of Polynomials: ");
    displayPoly(sum);

    // Multiplying the two polynomials
    Node* product = multiplyPoly(poly1, poly2);
    printf("Product of Polynomials: ");
    displayPoly(product);

    return 0;
}
