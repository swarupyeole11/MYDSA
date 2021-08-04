#include<bits/stdc++.h>
using  namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
//         int mini = INT32_MAX;
        
//         for(int i=0;i<nums.size();i++)
//         {
//             mini= min(mini,nums[i]);
//         }
        
        int cursum=0,finalsum=INT32_MIN;
    
        
        for(int i=0;i<nums.size();i++){
//         {
//               cursum=0;    
            
//            for(int j=i;j<nums.size();j++)
//            {
//               cursum=cursum+nums[j];     //GIVES TLE
//                //cout<<cursum<<" ";
//               finalsum = max(cursum,finalsum);
//                 cout<<finalsum<<" ";
//            }
            
        cursum=cursum+nums[i];
               
       
         if(cursum>finalsum)
        {
            finalsum=cursum;
        }
            
             if(cursum<0)
        {
            cursum=0;
        }
        
              
        
        }
        
        return finalsum;
        
    }
};
int main(){

    vector<int> v1;

    int element,size;

    cout<<"enter the size of array:";

    cin>>size;


    for(int i=0;i<size;i++)
    {
       cin>>element;
       v1.push_back(element);
    }
    
    Solution obj;

    cout<<obj.maxSubArray(v1);

  return 0;
}
   
