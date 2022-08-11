// Problem Link : https://leetcode.com/problems/validate-binary-search-tree/

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
public:
    bool validateBST(TreeNode* root, long minm, long maxm)
    {
        if(!root)
            return true;
        
        if(root->val <= minm or root->val >= maxm)
            return false;
        
        return validateBST(root->left, minm, root->val) and validateBST(root->right, root->val, maxm);
    }
    bool isValidBST(TreeNode* root) {
        
        return validateBST(root, LONG_MIN, LONG_MAX);
        
    }
};