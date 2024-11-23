#include <stdio.h>
#include <string.h>

// Student structure
typedef struct {
    char name[50];
    int roll_no;
    float total_marks;
} Student;

// Swap function
void swap(Student *a, Student *b, int *swap_count) {
    Student temp = *a;
    *a = *b;
    *b = temp;
    (*swap_count)++;
}

// Bubble Sort
void bubbleSort(Student arr[], int n, int *swap_count) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j].roll_no > arr[j+1].roll_no) {
                swap(&arr[j], &arr[j+1], swap_count);
            }
        }
    }
}

// Insertion Sort
void insertionSort(Student arr[], int n, int *swap_count) {
    int i, j;
    Student key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j].roll_no > key.roll_no) {
            arr[j + 1] = arr[j];
            (*swap_count)++;
            j--;
        }
        arr[j + 1] = key;
    }
}

// Merge function for Merge Sort
void merge(Student arr[], int l, int m, int r, int *swap_count) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    Student L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i].roll_no <= R[j].roll_no) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
            (*swap_count)++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort
void mergeSort(Student arr[], int l, int r, int *swap_count) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m, swap_count);
        mergeSort(arr, m + 1, r, swap_count);

        merge(arr, l, m, r, swap_count);
    }
}

// Partition function for Quick Sort
int partition(Student arr[], int low, int high, int *swap_count) {
	int j;
    int pivot = arr[high].roll_no;
    int i = (low - 1);

    for ( j = low; j <= high - 1; j++) {
        if (arr[j].roll_no < pivot) {
            i++;
            swap(&arr[i], &arr[j], swap_count);
        }
    }
    swap(&arr[i + 1], &arr[high], swap_count);
    return (i + 1);
}

// Quick Sort
void quickSort(Student arr[], int low, int high, int *swap_count) {
    if (low < high) {
        int pi = partition(arr, low, high, swap_count);

        quickSort(arr, low, pi - 1, swap_count);
        quickSort(arr, pi + 1, high, swap_count);
    }
}

// Function to print the array of students
void printStudents(Student arr[], int n) {
    printf("Name\tRoll No\tMarks\n");
    int i;
    for (i = 0; i < n; i++) {
        printf("%s\t%d\t%.2f\n", arr[i].name, arr[i].roll_no, arr[i].total_marks);
    }
}

int main() {
    int n,i,choice, swap_count = 0,num=1;

    printf("Enter the number of students: ");
    scanf("%d", &n);

    Student students[n];

    // Input student data
    
    for (i = 0; i < n; i++) {
        printf("Enter name of student %d: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter roll number of student %d: ", i + 1);
        scanf("%d", &students[i].roll_no);
        printf("Enter total marks of student %d: ", i + 1);
        scanf("%f", &students[i].total_marks);
    }

    // Menu for sorting options
    printf("\nChoose sorting technique:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Merge Sort\n");
    printf("4. Quick Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    


    switch (choice) {
        case 1:
            bubbleSort(students, n, &swap_count);
            break;
        case 2:
            insertionSort(students, n, &swap_count);
            break;
        case 3:
            mergeSort(students, 0, n - 1, &swap_count);
            break;
        case 4:
            quickSort(students, 0, n - 1, &swap_count);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
   

    // Print sorted student data
    printf("\nSorted list of students by roll number:\n");
    printStudents(students, n);

    // Print number of swaps performed
    printf("\nNumber of swaps performed: %d\n", swap_count);

    return 0;
}

