#include<bits/stdc++.h>
using  namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        
       int count0=0,count1=0,count2=0;
        
        for(int i=0; i<nums.size();i++)
        {
           if(nums[i]==0)
           {
               count0++;
           }
            
            if(nums[i]==1)
           {
               count1++;
           }
            
           if(nums[i]==2)
           {
               count2++;
           } 
            
            
        }
        
        
        // cout<<count0<<" "<<count1<<" "<<count2;
        
        int j;
        
        for( j=0; j<count0;j++)
        {
            nums[j]=0;
        }
        
        for(;j<count1+count0;j++)
        {
            nums[j]=1;
        }
        
        
        for(;j<count0+count1+count2;j++)
        {
            nums[j]=2;
        }
        
    }
};


int main(){

   Solution obj;
   
   vector<int> v1;

   int size,element;

   cout<<"Enter the size of the array:";
   
   cin>>size;

   for(int i=0;i<size;i++)
   {
      cin>>element;
      v1.push_back(element);
   }
   
   

   obj.sortColors(v1);


   for(int i=0;i<v1.size();i++)
   {
       cout<<v1[i];
   }
   




  return 0;
}
   
