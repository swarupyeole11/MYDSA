#include<bits/stdc++.h>
using  namespace std;


int main()
{ 
  
  int t;
  cin>>t;

 while(t--)
 {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
     cin>>arr[i];
  }

  for(int i=0;i<n-1;i++)
  {
      int sum = arr[i]+(i+1);

      if(sum%2==0)
      {
              swap(arr[i],arr[i+1]);
      }
  }

 int count =0;

  for(int i=0;i<n;i++)
  {
      int sum = arr[i]+(i+1);

      if(sum%2!=0)
      {
             count++;
      }
  }
  
  cout<<count<<endl;
  
 }
  return 0;
}
   