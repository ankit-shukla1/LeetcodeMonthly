// Problem Link : https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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
    void preOrderHelper(TreeNode* root, vector<int> &result){
        if(root == NULL)
            return;
        
        result.push_back(root->val);
        preOrderHelper(root->left, result);
        preOrderHelper(root->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {

        vector<int> result; 
        preOrderHelper(root, result);
        return result;
    }
};