#include<bits/stdc++.h>
using  namespace std;

int main(){
  
  int n;
  cin>>n;//no of unpaid bills

  int arr[n];

  for(int i=0;i<n;i++){
     cin>>arr[i];//each bill no.
  }

  int q;
  cin>>q;
  int arra[q];
  for(int i=0;i<q;i++){
     cin>>arra[i];
  }

  int l,h,flag,k,mid;

  

  for(int i=0; i<q; i++)
  {
     l = 0;
     h = n-1;


     flag=0;
     
     cout<<q;
     cout<<arra[i];
     cout<<"N"<<n;

    while(l<=h)
    {  

      cout<<'j';

        mid = (l+h)/2;

 
       if(arra[i]==arr[mid])
       {
          flag=1;
          cout<<"paid";
       }

       else if (arra[i]>arr[mid])
       {
          l=mid+1;
       }

       else
       {
          h=mid-1;
       }
    }

     
    // if(flag==0)
    // {
    //    cout<<"unpaid";
    // }
   }
  
    

  return 0;
}
   
