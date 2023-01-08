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
    void in(TreeNode *root, vector<int> &inorder)
    {
        if (root == NULL)
            return;

        if (root->left != NULL)
            in(root->left, inorder);
        inorder.push_back(root->val);
        if (root->right != NULL)
            in(root->right, inorder);
    }
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        vector<int> inorder;
        in(root1, inorder);
        in(root2, inorder);
        sort(inorder.begin(), inorder.end());
        return inorder;
    }
};