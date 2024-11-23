#include<stdio.h>

#define MAX 10  // Maximum number of vertices

int queue[MAX];

void Enqueue(int vertex);
int Dequeue();
int EmptyQueue();
void bfs (int matrix[10][10],int n);
void acceptGraph(int matrix[MAX][MAX], int n);
void displayGraph(int matrix[MAX][MAX], int n);

void acceptGraph(int matrix[MAX][MAX], int n) 
{
    int i,j;
    printf("Enter the adjacency matrix:\n");

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter value for matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayGraph(int matrix[MAX][MAX], int n) 
{
    int i,j;
    printf("The adjacency matrix is:\n");

    // Loop to display the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}


//Enueue elements
void Enqueue(int vertex) 
{
    int front= -1, rear=-1;
    if (rear == MAX - 1)
        printf("Queue is full\n");
    else {
        if (front == -1)
            front = 0;
        rear++;
        queue[rear] = vertex;
    }
}

// Function to dequeue elements
int Dequeue() 
{
    int front= -1, rear=-1;
    int vertex;
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return -1;
    } else {
        vertex = queue[front];
        front++;
        return vertex;
    }
}

int EmptyQueue() 
{
    int front= -1, rear=-1;
    return (front == -1 || front > rear);
}

void bfs (int matrix[10][10],int n)
    {
        int visited[10], v;

        for(v=0;v<n;v++)
        {
            visited[v]=0;           //initialized visited array
            printf("enter start vertex : ");
            scanf("%d",&v);

            Enqueue(v);             //1st vertex inserted in queue
            visited[v]=1;           //mark as visited
        }

        while(!EmptyQueue())
        {
            v=Dequeue();        //delete the vertex and store it in v
            printf("%d",v);         //display v

            for(int i=0;i<n;i++)
            {
                if(matrix[v][i]==1 && visited[i]==0)     //check the another adjacent vertex of that visited vertex
                {
                    Enqueue(i);
                    visited[i]=1;
                }
            }
        }
    }

int main()
{
    int n;  
    int matrix[MAX][MAX];  // Adjacency matrix

    printf("Enter the number of vertices: ");       // Accept the number of vertices from the user
    scanf("%d", &n);

    // Accept the graph as an adjacency matrix
    acceptGraph(matrix, n);

    // Display the adjacency matrix
    displayGraph(matrix, n);

    bfs(matrix,n);
    
}

