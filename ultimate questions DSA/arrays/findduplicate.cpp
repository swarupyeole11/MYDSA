#include<bits/stdc++.h>
using  namespace std;
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      
        int num=0;
        int maxi=INT32_MIN;
        int mini=INT32_MAX;
        
       
        
        for(int i=0;i<nums.size();i++)
        {
           maxi=max(maxi,nums[i]);
           mini=min(mini,nums[i]);
        }
        
        int h1[nums.size()];
        
        for(int i=0;i<nums.size();i++)
        {
            h1[i]=0;
        }
        
        for(int i=0;i<nums.size();i++)
        {
            h1[nums[i]]++;
        }
        
        for(int i=mini;i<=maxi;i++)
        {
            if(h1[i]>1)
            {
                num=i;
            }
        }
        
        //This solution is possible only for the given constraints
        
        return num;
    }
};
int main(){
  
  vector<int> v1;

    int element,size;

    cout<<"enter the size of vector array:";
    cin>>size;

    cout<<"enter array:";

    for (int i = 0; i < size; i++)
    {
        
        cin >> element;

        v1.push_back(element);

    }

  Solution pap;

  cout<<pap.findDuplicate(v1);
  

  return 0;
}
   
