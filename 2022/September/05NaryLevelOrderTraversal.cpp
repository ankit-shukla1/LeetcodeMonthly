// Problem Link : https://leetcode.com/problems/n-ary-tree-level-order-traversal/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>> result;
        
        if(!root)
            return result;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int k = q.size();
            vector<int> temp;
            
            while(k--)
            {
                Node* curr = q.front();
                q.pop();
                
                temp.push_back(curr->val);
                
                for(Node* x : curr->children)
                {
                    q.push(x);
                }
            }
            result.push_back(temp);
        }
        
        return result;
    }
};