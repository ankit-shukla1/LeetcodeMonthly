// Problem Link : https://leetcode.com/problems/range-sum-of-bst/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
        void helper(TreeNode* root, int &sum, int &low, int &high)
    {
        if(root == NULL)
            return;
        if(root->val >= low and root->val<= high)
                sum += root->val;
        if(root->val > low)
            helper(root->left, sum, low, high);
        if(root->val < high)
            helper(root->right, sum, low, high);
        

    }
public:

    int rangeSumBST(TreeNode* root, int low, int high) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int sum = 0;
        helper(root, sum, low, high);
        return sum; 
    }
};