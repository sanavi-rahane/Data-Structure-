#include<stdio.h>
int data[5];
int rear,front;
void initilize();
int full();
int empty();
void insertion();
void deletion();
void print();


int main()
{
	
	initilize();
	
	int ch;
	do
	{
		printf("\n 1.insertion ");
		printf("\n 2.deletion ");
		printf("\n 3.print ");
		printf("\n 4.Exit ");
		printf("\n Enter your choice ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:if(full()==0)
					{
						insertion();
					}
					else
					{
						printf("\n Queue is full ");
					}
					break;
			case 2:if(empty()==0)
					{
						deletion();
					}
					else
					{
						printf("\n Queue is empty ");
					}
					break;
			case 3:if(empty()==0)
			{
				
			print();
		}
		else
		{
			printf("\n nothing to print");
		}
			break;
			case 4:printf("\n Thanks for using our software");
			break;
			default:printf("\n plz enter valid choice ");
		}
	}while(ch!=4);
	return 0;
}
void initilize()
{
	rear=front=-1;
}
int full()
{
	if(rear==5-1)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
int empty()
{
	if(rear==-1)
	{
		return(1);
	}
	else
	{
		return(0);
	}
}
void insertion()
{
	int x;
	printf("\nEnter number for  insertion :");
	scanf("%d",&x);
	if(rear==-1)
	{
		rear=front=0;
		data[rear]=x;
	}
	else
	{
		rear=rear+1;
		data[rear]=x;
	}
	printf("\n Data inserted succesfully");
}
void deletion()
{
	
	int x;

	x=data[front];
	printf("\n data %d deleted ",x);
	front=front+1;
	
}
void print()
{
	int i;
	printf("\nQueue data : \n");
	if(rear==-1&&front==-1)
	{
	printf("queue is empty");
	}
	else
	{
	
		for(i=front;i<=rear;i++)
		{
			printf("\n%d\t",data[i]);
		}
   }
}

