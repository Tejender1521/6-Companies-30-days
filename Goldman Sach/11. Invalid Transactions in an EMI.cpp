#include<bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<string> separate(string &s)
    {
        vector<string> v;
        string t;
        for (auto it : s)
        {
            if (it == ',')
            {
                v.push_back(t);
                t.clear();
            }
            else
            {
                t.push_back(it);
            }
        }
        v.push_back(t);
        return v;
    }

    vector<string> invalidTransactions(vector<string> &transactions)
    {

        unordered_map<string, vector<string>> mp;
        for (int i = 0; i < transactions.size(); i++)
        {
            mp[transactions[i]] = separate(transactions[i]);
        }

        vector<string> Invalid;
        for (int i = 0; i < transactions.size(); i++)
        {
            vector<string> s = mp[transactions[i]];
            if (stoi(s[2]) > 1000)
            {
                Invalid.push_back(transactions[i]);
                continue;
            }
            for (int j = 0; j < transactions.size(); j++)
            {
                if (i != j)
                {
                    vector<string> t = mp[transactions[j]];
                    if (abs(stoi(t[1]) - stoi(s[1])) <= 60)
                    {
                        if (t[0] == s[0] && t[3] != s[3])
                        {
                            Invalid.push_back(transactions[i]);
                            break;
                        }
                    }
                }
            }
        }
        return Invalid;
    }
};