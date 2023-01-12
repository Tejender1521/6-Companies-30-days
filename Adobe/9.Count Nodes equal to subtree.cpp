#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    pair<int, int> dfs(TreeNode *node, int &cnt)
    {
        if (!node)
            return {0, 0};

        auto left_subtree = dfs(node->left, cnt);
        auto right_subtree = dfs(node->right, cnt);

        int sum = left_subtree.first + right_subtree.first + node->val;
        int count = 1 + left_subtree.second + right_subtree.second;

        if (sum / count == node->val)
            cnt++;

        return {sum, count};
    }

    int averageOfSubtree(TreeNode *root)
    {
        int cnt = 0;
        dfs(root, cnt);
        return cnt;
    }
};