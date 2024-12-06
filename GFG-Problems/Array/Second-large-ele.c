#include<stdio.h>
int getSecondLargest(int arr[], int n);

    // Function returns the second
    // largest elements
int getSecondLargest(int arr[], int n)
 {
        
       int size=sizeof(arr);
       
//*********************
       //Approch 1 sorting an array using buble sort and then return second largest
          
            // for(int i=0;i<size;i++)
            // {
            //     for(int j=i+1;j<size;j++)
            //     {
            //         if(arr[i]>arr[j])
            //         {
            //             int temp=arr[i];
            //             arr[i]=arr[j];
            //             arr[j]=temp;
            //         }
            //     }
            // }
            
            // for(int i=size-1;i>=0;i--)
            // {
            //     if(i-1==-1)
            //     {
            //         return -1;
            //     }
            //     else if(arr[i]!=arr[i-1])
            //     {
            //         return arr[i-1];
            //     }    
            // }
        
        
//******************************   
        
        
        
        
 //approch 2 by finding a largest element first and then second large
        // int lar=-1;
        // for(int i=0;i<size-1;i++) //12 3 4 1 
        // {
        //     if(arr[i]>arr[i+1]&&arr[i]>lar)
        //     {
        //          lar=arr[i]; //12
                
        //     }
            
            
        // }
        // return lar;
        // int sm=-1;
        // for(int i=0;i<size-1;i++)
        // {
        //     if(arr[i]<lar||arr[i]<sm)
        //     {
        //          sm=arr[i];
        //     }
        // }
        // return sm;
        
        
//------------------------------------------
        // int lar=arr[0];
        // int sm=-1;
        // for(int i=1;i<size-1;i++)
        // {
        //     if(arr[i]>lar)
        //     {
        //         lar=arr[i];
        //     }
        // }
        // return lar;
        
        // for(int i=0;i<size-1;i++)
        // {
        //     if(arr[i]!=lar&&arr[i]>sm)
        //     {
        //         sm=arr[i];
        //     }
        // }
        // return sm;
        
        
//***********************      
        //approch 3 by keeping a track of largest and second larg element
        
        int lar=arr[0];
        int prev=-1;
        for(int i=1;i<size;i++)
        {
            if(arr[i]>lar)
            {
                prev=lar;
                lar=arr[i];
            }
            if(arr[i]>prev&&arr[i]!=lar)
            {
                prev=arr[i];
            }
        }
        
        return prev;
        
//***************************
        
     }


int main()
{
    int n;
    int arr[n];
    printf("Enter Size Of array\t");
    scanf("%d",&n);
    printf("Enter array element\t");
    for(int j=0;j<n-1;j++)
    {
        scanf("%d",&arr[j]);
    }
    int ans = getSecondLargest(arr, n);
    printf("Second Largest Element is :\n %d",ans);

    
}