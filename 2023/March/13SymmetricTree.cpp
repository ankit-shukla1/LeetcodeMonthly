// Problem Link : https://leetcode.com/problems/symmetric-tree/description/

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
    static bool helper(TreeNode* node1, TreeNode* node2){
        if(node1 == NULL and node2 == NULL)
            return true;
        if(node1 == NULL || node2 == NULL)
            return false;
        
        return (node1->val == node2->val) && (helper(node1->left, node2->right)) && (helper(node1->right, node2->left)); 
    }
public:
    bool isSymmetric(TreeNode* root) {

        if(!root)
            return true;
        
        return helper(root->left, root->right);
        
    }
};