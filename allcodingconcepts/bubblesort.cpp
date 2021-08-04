#include<bits/stdc++.h>
using  namespace std;


void bubblesort(int arr[],int n)
{
   for(int i=0;i<n-1;i++)
   {
      for(int j=0;j<n-1-i;j++)
      {
          if(arr[j]>arr[j+1])
          {
              swap(arr[j],arr[j+1]);
          }
      }
      
   }
   
}


void insertionsort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int x = arr[i];
        int j = i-1;
        while(arr[j]>x&&j>-1)
        {
          arr[j+1]=arr[j];
          j--;
          
        }

        arr[j+1]=x;
    }
    
}


int main(){

   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }

   insertionsort(arr,n);
   
   for(int i=0;i<n;i++){
      
      cout<<arr[i];
   }
   
   


  return 0;
}
   
