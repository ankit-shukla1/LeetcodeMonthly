// Problem Link : https://leetcode.com/problems/find-if-path-exists-in-graph/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        vector<vector<int>> um(n);
        vector<bool> visited(n, false);
        for(auto x : edges){
            um[x[0]].push_back(x[1]);
            um[x[1]].push_back(x[0]);
        }

        queue<int> q;
        q.push(start);
        while(q.empty()==false){
            int curr = q.front();q.pop();
            if(curr == end){
                return true;
            }
            for(auto x : um[curr]){
                if(visited[x]==false){
                    q.push(x);
                    visited[curr] = true;
                }
            }
        }

        return false;
    }
};