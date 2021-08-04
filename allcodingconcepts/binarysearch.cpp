#include<bits/stdc++.h>
using  namespace std;

int binarysearch(int low,int high,int key,int arra[])
{
     
    sort(arra,arra+high);//sorts in nlogn T.C

    while(low<=high)
    {
        int mid = (low+high)/2;

        if (arra[mid]==key)
        {
            return mid;
        }

        else if (arra[mid]>key)
        {
            high=mid-1;
        }

        else
        {
            low = mid+1;
        }
    }
    
  return -1;  
}


int linearsearch(int arr[],int num,int key)  
{

   for(int i=0;i<num;i++)
   {
      if (arr[i]==key)
      {
          return i;
      }
   }
   
   return -1; 
}




int main(){

   int key;
   cout<<"enter the key:";
   cin>>key;


   cout<<"enter the size of array";
   int n;
   cin>>n;
   int arr[n];

   cout<<"enter the elements:";
   
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }

   int l=arr[0],h=arr[n-1];
   
   int keyindexb = binarysearch(l,h,key,arr);
   
   int keyindexl = linearsearch(arr,n,key);

   cout<<keyindexl;


  return 0;
}
   
