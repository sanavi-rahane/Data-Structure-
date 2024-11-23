#include<stdio.h>
int top;
int data[5];
int full();
int empty();
void initilize();
void push();
void pop();
void print();
int main()
{
	int ch;
	initilize();
	do
	{
		printf("\n 1.print");
		printf("\n 2.push ");
		printf("\n 3.pop ");
		printf("\n 4.Exit ");
		printf("\nEnter youe choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:print();
			break;
			case 2:if(full()==0)
			{
				push();
			}
			else
			{
				printf("\nstack is full");
			}
			break;
			case 3:if(empty()==0)
			{
				pop();
			}
			else
			{
				printf("stack is empty");
			}
			break;
			case 4:printf("\n Thanks for using our softwar ");
			break;
			default:
				printf("\nplz enter valid choice ");
				
		}
	}while(ch!=4);
}
int full()
{
	if(top==5-1)
	return(1);
	else
	return(0);
}
int empty()
{
	if(top==-1)
	return(1);
	else
	return(0);
}
void initilize()
{
	top=-1;
}
void push()
{
	int x;
	printf("\n Enter data for insertion ");
	scanf("%d",&x);
	top=top+1;
	data[top]=x;
	printf("\n data inserted ");
}
void pop()
{
	int x;
	data[top]=x;
	top=top-1;
	printf("\n data %d deleted ",x);
}
void print()
{
	int i;
	printf("\n stack data ");
	for(i=0;i<=top;i++)
	{
		printf("%d\t",data[i]);
	}
}
