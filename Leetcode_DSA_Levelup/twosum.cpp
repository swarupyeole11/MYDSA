#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {

        // IT IS A O(NLOGN) SOLUTION
        vector<int> checkarr = nums;

        sort(checkarr.begin(), checkarr.end());
        int i = 0, j = nums.size() - 1;
        int val1;
        int val2;

        vector<int> ans;

        while (i < j)
        {
            if (checkarr[i] + checkarr[j] == target)
            {
                val1 = checkarr[i];
                val2 = checkarr[j];
                break;
            }

            else if (target > checkarr[i] + checkarr[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == val1)
            {
                ans.push_back(i);
                break;
            }
        }

        for (int j = nums.size() - 1; j >= 0; j--)
        {
            if (nums[j] == val2)
            {
                ans.push_back(j);
                break;
            }
        }

        return ans;
    }
};

int main()
{ 
    
    return 0;
}


