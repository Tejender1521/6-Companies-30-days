#include<bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int maxFruits = 0;
        int left = 0, right = 0;
        unordered_map<int, int> fruitCount;
        while (right < n)
        {
            fruitCount[fruits[right]]++;
            while (fruitCount.size() > 2)
            {
                fruitCount[fruits[left]]--;
                if (fruitCount[fruits[left]] == 0)
                {
                    fruitCount.erase(fruits[left]);
                }
                left++;
            }
            maxFruits = max(maxFruits, right - left + 1);
            right++;
        }
        return maxFruits;
    }
};