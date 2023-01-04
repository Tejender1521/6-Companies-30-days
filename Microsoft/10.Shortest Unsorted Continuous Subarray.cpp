#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        vector<int> temp(nums);
        sort(temp.begin(), temp.end());
        int i = 0, j = nums.size();
        if (temp == nums)
        {
            return 0;
        }
        for (int itr = 0; itr < nums.size(); itr++)
        {
            if (nums[itr] != temp[itr])
            {
                i = itr;
                break;
            }
        }
        for (int itr = nums.size() - 1; itr >= 0; itr--)
        {
            if (nums[itr] != temp[itr])
            {
                j = itr;
                break;
            }
        }
        return j - i + 1;
    }
};