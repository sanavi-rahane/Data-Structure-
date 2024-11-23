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
node* insert(node *head,int loc,int no);

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

node* insert(node *head,int loc,int no)
{
	int i;
	node *p,*q;
	p=(node*)malloc(sizeof(node));
	p->data=no;
	p->next=NULL;
	
	if(loc==1)
	{
		p->next=head;
		head=p;
		return (head);
	}

	                                          
		q=head; 
		                     	
		for(i=1;i<loc-1;i++)                    
		{
			if(q!=NULL)
			{
					q=q->next;
			}
		}	
			if(q==NULL)
			{
				printf("overflow");
				return (head);
				
			}
			else
			{
				p->next=q->next;
				q->next=p;
				return (head);
			}
		
	
	

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
	int n,x,loc,no;
	
	node *head;
	
	printf("Enter the number of nodes");
	scanf("%d",&n);
	
	head=create(n);
	print(head);
	
	x=count(head);
	printf("\nnumber of nodes : %d",x);
	
	printf("\nEnter A number For Inserton ");
	scanf("%d",&no);
	
	printf("\nEnter a location");
	scanf("%d",&loc);
	
	head=insert(head,loc,no);
	
	printf("\nAfter Insertion LL:");
	print(head);
	x=count(head);
	printf("\nnumber of nodes : %d",x);
	
	
}
