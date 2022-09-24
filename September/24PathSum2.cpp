// Problem Link : https://leetcode.com/problems/path-sum-ii/

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
    
    void helper(TreeNode* root, int targetSum, int currSum, vector<int> currVec, vector<vector<int>> &result){
        
        //check for null
        if(!root)
            return;
        
        currSum += root->val;
        currVec.push_back(root->val);
        if(root->left == NULL and root->right == NULL){
            if(currSum == targetSum){
                result.push_back(currVec);
            }
            return;
        }
        helper(root->left, targetSum, currSum, currVec, result);
        helper(root->right, targetSum, currSum, currVec, result);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>> result;
        vector<int> currVec;
        int currSum=0;
        
        helper(root, targetSum, currSum, currVec, result);
        return result;
        
    }
};
