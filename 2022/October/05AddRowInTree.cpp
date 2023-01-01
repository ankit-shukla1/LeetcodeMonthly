// Problem Link : https://leetcode.com/problems/add-one-row-to-tree/description/


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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {

        queue<TreeNode*> q;
        q.push(root);
        int currDepth = 1;

        if(depth == 1)
        {
            TreeNode* curr = new TreeNode(val);
            curr->left = root;
            return curr;
        }

        while( currDepth < depth){
            int k = q.size();
            // cout<<currDepth<<" : ";
            while(k--)
            {
                TreeNode* curr = q.front();
                q.pop();
                // cout<<curr->val<<" ";
                if(currDepth == depth-1){
                    TreeNode* leftNode = new TreeNode(val);
                    TreeNode* currLeft = curr->left;
                    curr->left = leftNode;
                    leftNode->left = currLeft;

                    TreeNode* rightNode = new TreeNode(val);
                    TreeNode* currRight = curr->right;
                    curr->right = rightNode;
                    rightNode->right = currRight;
            }
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                        q.push(curr->right);
            }
            // cout<<"\n";
            currDepth++;
        }
        return root;
        
    }
};