#include<bits/stdc++.h>
using  namespace std;

//NOTE THAT IN TEST CASES THEY HAVE CONSIDERED INDEXING FROM 1
int main()
{
  int t;
  cin>>t;

  while (t--)
  {
      int n;
      cin>>n;
      int arr[n];
      for(int i=1;i<=n;i++){
         cin>>arr[i];
      }

        int Q; // Number of queries
       cin>>Q;
 
   while (Q--)
   {
    int L,R;
    cin>>L>>R;

    int infiarr[R];
    int i;

    for( i=1;i<=n;i++)
    {
       infiarr[i]=arr[i];
      // cout<<arr[i]<<" ";
    }

    int k=1;
    

    for( ;i<=R;i++)
    { 

       infiarr[i]=arr[i-n*k];  // for e.g 4-1*3 5-1*3 6-1*3 //

       // cout<<"i-n*k : "<<i-n*k<<" "<<"i: "<<i<<" ";
       // cout<<"--"<<infiarr[i]<<" "<<" -- ";
        if((i-n*k)==n)
       {
          k++;
       }
        
       
    }
    
    
    
    int Sumarr[R];
    Sumarr[0]=0;

    for(int i=1;i<=R;i++)
    {
         Sumarr[i]=infiarr[i]+Sumarr[i-1];
    }

    cout<<(Sumarr[R]-Sumarr[L-1])%(10*10*10*10*10*10*10*10*10 + 7)<<" ";
    
   }
 
  

  }

 
  

  return 0;
}
   
