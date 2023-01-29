#include<bits/stdc++.h>

using namespace std;

class Solution
{
private:
    int mod = 1000000000 + 7;

public:
    int maxSumMinProduct(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i < prefix.size(); i++)
        {
            prefix[i] = prefix[i - 1] + (long long)nums[i - 1];
        }
        vector<int> left(n, 0), right(n, n);
        vector<int> stack;
        for (int i = 0; i < n; i++)
        {
            while (stack.size() and nums[stack.back()] > nums[i])
            {
                right[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        stack.clear();
        for (int i = n - 1; i >= 0; i--)
        {
            while (stack.size() and nums[stack.back()] > nums[i])
            {
                left[stack.back()] = i + 1;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long rangeSum = prefix[right[i]] - prefix[left[i]];
            long long currProduct = (long long)nums[i] * rangeSum;
            ans = max(ans, currProduct);
        }
        return ans % mod;
    }
};