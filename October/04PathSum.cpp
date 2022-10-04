// Problem Link :  https://leetcode.com/problems/path-sum/description/


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
    void helper(TreeNode* root, int &targetSum, int &currSum, int &result)
    {
        if(root==NULL)
            return;
        
        currSum += root->val;

        if(root->left == NULL and root->right==NULL)
        {
            if(currSum == targetSum)
            {
                result = true;
            }
        }
        
        helper(root->left, targetSum, currSum, result);
        helper(root->right, targetSum, currSum, result);
        currSum -= root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {

        int currSum = 0;
        int result = false;
        helper(root, targetSum, currSum, result);
        return result;
        
    }
};