// Problem Link : https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        unordered_map<int, int> um;

        for(int i=0; i<matches.size(); i++)
        {
            if(um.find(matches[i][0]) == um.end())
            {
                um[matches[i][0]] = 0;
            }
            um[matches[i][1]]++;
        }
        vector<vector<int>> result(2);
        for(auto x : um)
        {
            if(x.second == 0)
                result[0].push_back(x.first);
            if(x.second == 1)
                result[1].push_back(x.first);
        }

        sort(result[0].begin(), result[0].end());
        sort(result[1].begin(), result[1].end());

        return result;
        
    }
};