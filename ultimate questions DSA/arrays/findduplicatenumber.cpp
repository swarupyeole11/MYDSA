#include<bits/stdc++.h>
using  namespace std;
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
      
      //vector<int> v1;
      
     // int H[n]={0};
      
    //   for(int i=0;i<n;i++)
    //   {
    //       H[arr[i]]+=1;
    //   }
      
    //   int flag=0;
      
    //   for(int i=0;i<n;i++)
    //   {
    //       if(H[i]>1)
    //       {   
    //           flag=1;
    //           v1.push_back(i);
    //           H[i]=0;
    //       }
    //   }
      
    //   if(flag==0)
    //   {   
    //       v1.push_back(-1);
    //       return v1;
    //   }
      
    ////THE ABOVE SOLUTION WAS USING HASJH TABLE ALTHOOUGH REDUCES TIME COMPLEXITY IT INCRREASES SPACE COMPLEXXITY//
    ///
    ///
    ///
    
    //----------------------------------------------------------------------------------------------------------------------------------------------------------------------

    //     vector<int> v1;
        
    //     sort(arr,arr+n);
    //     int flag=0;
        
    //     for(int i=0;i<n;i++)
    //     {
    //         if((arr[i]==arr[i+1])&&(arr[i]!=arr[i-1]))
    //         {  
    //             // cout<<arr[i]<<" ";
                
    //             if(arr[i]==0)
    //             {
    //                 v1.push_back(0);
    //             }
    //             else
    //             {
    //             v1.push_back(arr[i]);
    //             }
                
    //             flag=1;
    //         }
    //     }
        
    //     if(flag==0)
    //   {   
    //       v1.push_back(-1);
    //       return v1;
    //   }
    
    //    return v1;
    // }


     ////THE ABOVE SOLUTION WAS O{NLogN) time  and O(1) space
    ///
    ///
    ///

    //--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------//

   


    }
};

int main()
{
   int n;
   cout<<"enter the array size:";
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
      cin>>arr[i];
   }
   
   Solution pappu;

   vector<int> final;

   final = pappu.duplicates(arr,n);

   for(int i=0;i<final.size();i++)
   {
       cout<<final[i]<<" ";
   }
   

  return 0;
}
   
