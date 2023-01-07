#include<bits/stdc++.h>

using namespace std;
class Solution
{
public:
    int minimumCardPickup(vector<int> &cards)
    {
        unordered_map<int, int> mp;
        int ans = INT_MAX;
        for (int i = 0; i < cards.size(); i++)
        {
            if (mp[cards[i]] > 0)
            {

                ans = min(ans, i - mp[cards[i]]);
                mp[cards[i]] = i + 1;
            }
            else
            {
                mp[cards[i]] = i + 1;
            }
        }
        return (ans < cards.size()) ? ans + 2 : -1;
    }
};