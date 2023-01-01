// Problem Link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

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
    TreeNode* createBST(int start, int end, vector<int> &nums)
    {
        if(start>end)
            return NULL;
        
        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = createBST(start, mid-1, nums);
        root->right = createBST(mid+1, end, nums);
        
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int start = 0, end = nums.size()-1;
        
        return createBST(start, end, nums);
        
    }
};