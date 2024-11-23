#include <stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;
node* create(int n);
void print(node *p);
int main()
{
    int N;
    node *Head;
    Head=NULL;
    printf("How much node of linked list do you want to create : ");
    scanf("%d",&N);
    Head=create(N);
    print(Head);
    return 0;
}
node* create(int n)
{                 
    int x,i;
    node *head,*p;
    printf("Enter data : ");
    scanf("%d",&x);
    head=(node*)malloc(sizeof(node));
    head->data=x;
    head->next=NULL;
    p=head;
    for(i=2;i<=n;i++)
    {
        printf("Enter data : ");
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
    printf("SLL node ");
    while(p!=NULL)
    {
        printf("%d->",p->data);
        p=p->next;
    }
}

