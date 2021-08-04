#include<bits/stdc++.h>
using  namespace std;


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        sort(nums.begin(),nums.end());
        
        int n = nums.size();
        
        for (int i=0;i<n/2;i++)
        {
            swap(nums[i],nums[n-i-1]);
        }
        
        int ksmall = INT32_MAX;
        
        int count = 0;
        
        for (int i=0 ; i<n ; i++)
        {
            if(nums[i]<=ksmall)
            {
                ksmall=nums[i];
                count++;
            }
            
            if(count==k)
            {
                break;
            }
        }
        
        return ksmall;
       
    }
};


int main()
{
 

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

    int k;

    cout<<"enter the kth largest elemnt you want:";

    cin>>k;

    Solution pappu; //Solution is class name and pappuect is the pappuect variable for acessing functions in the class it can be named anything e.g pappu

    cout<<pappu.findKthLargest(v1,k);


  return 0;
}
   
