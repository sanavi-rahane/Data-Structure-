#include<stdio.h>

int main()
{
    int i,n,j,temp;
    int a[25];

    printf("Enter size of array : ");
    scanf("%d",&n);
    
    printf("\nEnter elements for array : ");
   for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Your Array elements are : ");
    for(i=0;i<=n;i++)
    {
        printf("%d",a[i]);
        
    }

    //Insertion Sort/
    for(i=1;i<n;i++)
    {
    	temp=a[i];
    	for(j=i-1;j>=0 && a[j]>temp;j--)
    	{
    		a[j+1]=a[j];
		}
		a[j+1]=temp;
	}
    
    
    
    printf("\nYour Sorted Array elements are : ");
   for(i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}

