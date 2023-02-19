// Problem Link : https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int>> result;
        if(root == NULL)
            return result;

        stack<TreeNode*> s1, s2;
        s1.push(root);

        while(s1.empty() == false || s2.empty() == false){
            int stackSize1 = s1.size();
            vector<int> temp;
            while(stackSize1--){
                TreeNode* curr = s1.top();
                temp.push_back(curr->val);
                if(curr->left){
                    s2.push(curr->left);
                }
                if(curr->right){
                    s2.push(curr->right);
                }
                s1.pop();
            }
            if(temp.size()>0)
                result.push_back(temp);
            temp.clear();
            int stackSize2 = s2.size();
            while(stackSize2--){
                TreeNode* curr = s2.top();
                temp.push_back(curr->val);
                if(curr->right){
                    s1.push(curr->right);
                }
                if(curr->left){
                    s1.push(curr->left);
                }
                s2.pop();
            }
            if(temp.size()>0)
                result.push_back(temp);

        }
        return result;
        
    }
};