#include<stdio.h>

int main()
{
    int i,n,j,temp;
    int a[25];

    printf("Enter size of array : ");
    scanf("%d",&n);
    
    printf("\nEnter elements for array : ");
   for(i=0;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Your Array elements are : ");
    for(i=0;i<=n;i++)
    {
        printf("%d",a[i]);
        
    }

    //bubble sort/
    for(j=0;j<=n;j++)
    {
        for(i=0;i<=n-1;i++)
        {
            if(a[i+1]<a[i])
            {
                temp=a[i+1];
                a[i+1]=a[i];
                a[i]=temp;
            }
        }
    }
    printf("\nYour Sorted Array elements are : ");
   for(i=0;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
