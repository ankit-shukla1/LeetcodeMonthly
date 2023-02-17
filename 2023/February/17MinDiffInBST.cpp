// Problem Link : https://leetcode.com/problems/minimum-distance-between-bst-nodes/description/

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
    static void traverse(TreeNode* root, vector<int> &sortedBST){
        if(root){
            traverse(root->left, sortedBST);
            sortedBST.push_back(root->val);
            traverse(root->right, sortedBST);
        }
    }
public:
    int minDiffInBST(TreeNode* root) {
        
        vector<int> sortedBST;
        traverse(root, sortedBST);

        int result = INT_MAX;

        for(int i=1; i<sortedBST.size(); i++){
            result = min(result, (sortedBST[i] - sortedBST[i-1]));
        }

        return result;
    }
};