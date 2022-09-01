// Problem Link : https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int countGoodNodes(TreeNode* root, int maxm)
    {
        if(root == NULL)
            return 0;
        
        maxm = max(root->val, maxm);
        
        if(root->val >= maxm)
            return 1 + countGoodNodes(root->left, maxm) + countGoodNodes(root->right,maxm);

        return countGoodNodes(root->left, maxm) + countGoodNodes(root->right,maxm);
    }
    int goodNodes(TreeNode* root) {
        
        return countGoodNodes(root, INT_MIN);
    }
};