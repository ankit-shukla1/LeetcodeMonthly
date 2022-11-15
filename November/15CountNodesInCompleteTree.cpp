// Problem Link : https://leetcode.com/problems/count-complete-tree-nodes/description/


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
    int countNodes(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        int leftHeight = 0, rightHeight = 0;
        
        TreeNode* leftRoot = root; TreeNode* rightRoot = root;
        
        while(leftRoot != NULL)
        {
            leftRoot = leftRoot -> left;
            leftHeight++;
        }
        
        while(rightRoot != NULL)
        {
            rightRoot = rightRoot -> right;
            rightHeight++;
        }
        
        if(leftHeight == rightHeight)
            return ((1<<leftHeight) - 1);
        
        return (1+countNodes(root->left)+countNodes(root->right));
        
    }
};