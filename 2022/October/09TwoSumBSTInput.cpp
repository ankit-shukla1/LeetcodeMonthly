// Problem Link : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    void preOrder(TreeNode* root, vector<int> &values){
        if(!root)
            return;
        preOrder(root->left, values);
        values.push_back(root->val);
        preOrder(root->right, values);
    }
    bool findTarget(TreeNode* root, int k) {

        vector<int> bstValues;
        preOrder(root, bstValues);

        int n = bstValues.size();
        int start=0, end=n-1;
        while(start<end){
            int sum = bstValues[start] + bstValues[end];
            if(sum == k)
                return true;
            else if(sum>k)
                end--;
            else    
                start++;
        }
        return false;

        
    }
};/**
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
    void preOrder(TreeNode* root, vector<int> &values){
        if(!root)
            return;
        preOrder(root->left, values);
        values.push_back(root->val);
        preOrder(root->right, values);
    }
    bool findTarget(TreeNode* root, int k) {

        vector<int> bstValues;
        preOrder(root, bstValues);

        int n = bstValues.size();
        int start=0, end=n-1;
        while(start<end){
            int sum = bstValues[start] + bstValues[end];
            if(sum == k)
                return true;
            else if(sum>k)
                end--;
            else    
                start++;
        }
        return false;

        
    }
};