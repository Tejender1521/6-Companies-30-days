#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void combination(int start, int k, int n, vector<int>& ds , vector<vector<int>>& ans)
    {
        if(k<0 || n<0)
        {
            return;
        }
        if(k==0 && n==0)
        {
            ans.push_back(ds);
        }
        for(int i=start;i<=9;i++)
        {
            ds.push_back(i);
            combination(i+1,k-1,n - i,ds,ans);
            ds.pop_back();
        }
    }


    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        combination(1,k,n,ds,ans);
        return ans;
    }
};