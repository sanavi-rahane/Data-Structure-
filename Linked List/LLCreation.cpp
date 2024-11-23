#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int data;
	struct node *next;
}node;

node* create(int n); 
void print(node*);   
int count(node*p);



node* create(int n)
{
	node *p,*head;  
	int i;
	
	head=(node*)malloc(sizeof(node)); 
	head->next=NULL;        
	scanf("%d",&(head->data));     
	
	p=head;  
	for(i=1;i<n;i++)
	{
		p->next=(node*)malloc(sizeof(node));  
		p=p->next;   
		scanf("%d",&p->data);
		p->next=NULL;    
		 
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
	int n,x;
	
	node *head;
	
	printf("Enter the number of nodes");
	scanf("%d",&n);
	
	head=create(n);
	print(head);
	
	x=count(head);
	printf("\nnumber of nodes : %d",x);
}
