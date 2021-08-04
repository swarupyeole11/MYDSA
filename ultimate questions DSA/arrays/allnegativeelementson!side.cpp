#include<bits/stdc++.h>
using  namespace std;

int main(){
  
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
     cin>>arr[i];
  }

  int i=0,j=n-1;

  while(i<j)
  {
      while(arr[i]>=0)// looks for neagtive number
      {
          i++;
      }

      while(arr[j]<0)// looks for positiveor0 number
      {
          j--;
      }
      

      cout<<i<<" "<<j<<" "<<endl;
      if(i<j){
      swap(arr[i],arr[j]);
       i++;
       j--;
       }
       
  }

  for(int i=0;i<n;i++)
  {
     cout<<arr[i]<<" ";
  }
  


  return 0;
}
   

/*PARTLY OPTIMIZED THAN PREVIOUS  2 POINTER APPROACH*/





  

