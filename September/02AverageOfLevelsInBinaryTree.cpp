// Problem Link : https://leetcode.com/problems/average-of-levels-in-binary-tree/

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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> result;
        
        if(root==NULL)
            return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        double sum=0;
        
        while(q.empty() == false)
        {
            int k = q.size(), queueSize = q.size();
            
            while(k--)
            {
                TreeNode* curr = q.front();
                q.pop();
                sum += curr->val;
                
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
            
            double average = (sum/queueSize);
            result.push_back(average);
            sum=0;
        }
        
        return result;
        
    }
};