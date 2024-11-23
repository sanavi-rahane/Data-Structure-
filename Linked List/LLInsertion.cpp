#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}node;

node* create(int n); //for creating linked list
void print(node*);   
int count(node*p);

node* insertAtBegin(node *head,int no);

node* create(int n)
{
	node *p,*head;  //here we declare a two empty node head and p
	int i;
	
	head=(node*)malloc(sizeof(node)); //here we give size to head
	head->next=NULL;        
	scanf("%d",&(head->data));     //assign value to head data
	
	p=head;  // p is equal to head
	for(i=1;i<n;i++)
	{
		p->next=(node*)malloc(sizeof(node));  // p next ko size
		p=p->next;   
		scanf("%d",&p->data);  //p ka data
		p->next=NULL;    // p ka next null
		 
	}
	return (head);
}


void print(node *p)
{
	while(p!=NULL)
	{
		printf("%d->",p->data);
		p=p->next;
	}
}

node* insertAtBegin(node *head,int no)
{
	node *p;
	p=(node*)malloc(sizeof(node));
	p->data=no;
	p->next=head;
	head=p;
	return (head);
}
node* insertAtEnd(node *head,int no)
{
	node *p,*q;
	p=(node*)malloc(sizeof(node));
	p->data=no;
	p->next=NULL;
	q=head;
	if(head==NULL)
	{
		head=p;
		return (head);
	}
	
	
	
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=p;
	return (head);
	
}
node* insertInBetween(node *head,int no,int key)
{
	node *p,*q;
	p=(node*)malloc(sizeof(node));
	p->data=no;
	p->next=NULL;
		q=head;
		while(q->data!=key&&q!=NULL)
		{
			q=q->next;
			if(q!=NULL)
			{
				p->next=q->next;
				q->next=p;
			}
		}
		return (head);
	

}


int count(node *p)
{
	int i=0;
	while(p!=NULL)
	{
		p=p->next;
		i++;
	}
	return(i);
}
int main()
{
	int n,x,key,no;
	
	node *head;
	
	printf("Enter the number of nodes");
	scanf("%d",&n);
	
	head=create(n);
	print(head);
	
	x=count(head);
	printf("\nnumber of nodes : %d",x);
	
	printf("\nEnter A number For Inserton ");
	scanf("%d",&no);
	
	//Insertion At Begin
	head=insertAtBegin(head,no);
	printf("\nAfter Insertion At Begin");
	print(head);
	x=count(head);
	printf("\nnumber of nodes : %d",x);
	
	//Insertion In Between
	printf("\nEnter A number For Inserton in between ");
	scanf("%d",&no);
	printf("\nEnter a number after which you wants to insert ");
	scanf("%d",&key);
	head=insertInBetween(head,no,key);
	printf("\nAfter Insertion In Between");
	print(head);
	x=count(head);
	printf("\nnumber of nodes : %d",x);
	
	//Insert At End
	printf("\nEnter A number For Inserton at end");
	scanf("%d",&no);
	head=insertAtEnd(head,no);
	printf("\nAfter Insertion At  End");
	print(head);
	x=count(head);
	printf("\nnumber of nodes : %d",x);
	
}
