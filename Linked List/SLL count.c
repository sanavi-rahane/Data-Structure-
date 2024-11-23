#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;                              
node* create(int n);                
void print(node *p); 
void count(node *p);               
int main()
{
    node *Head;
    int N;
    Head=NULL;                
    printf("\nEnter how much node of linked list do you want : ");
    scanf("%d",&N);
    Head=create(N);
    print(Head);
    count(Head);
}
node* create(int n)
{
    
    node *head,*p;
    int x,i;
    printf("\n enter data");
    scanf("%d",&x);
    head=(node*)malloc(sizeof(node));
    head->data=x;
    head->next=NULL;
    p=head;
    for(i=2;i<=n;i++)
    {
        printf("\n enter data");
        scanf("%d",&x);
        p->next=(node*)malloc(sizeof(node));
        p=p->next;
        p->data=x;
        p->next=NULL;
    }
    return(head);
    
}
void print(node *p)
{
    printf("\n SLL program ");
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
        
    }
}

void count(node *p)
{
    int count=0;
    while(p!=NULL)
    {
        count++;
        p=p->next;
        
    }
    printf("\n No of node pesent in linked list is : %d",count);
}





















/*#include<stdio.h>
typedef struct node
{
    int data;
    struct node *next;
}node;                              
node* create(int n);                 
void print(node *p);                
int main()
{
    node *Head;
    int N;
    Head=NULL;                  
    printf("\nEnter how much node of linked list do you want : ");
    scanf("%d",&N);
    Head=create(N);
    print(Head);
}
node create(int n)
{
    
    node *Head,*p;
    int x,i;
    printf("\n enter data");
    scanf("%d",&x);
    Head=(node*)malloc(sizeof(node));               
    Head->data=x;
    Head->next=NULL;
    p=Head;
    for(i=2;i<=n;i++)
    {
        printf("\n enter data");
        scanf("%d",&x);
        p->next=(node*)malloc(sizeof(node));
        p=p->next;
        p->data=x;
        p->next=NULL;
    }
    return(Head);
    
}
node print(node *p)
{
    printf("\n SLL program ");
    while(*p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
        
    }
}*/
