// Problem Link : https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int, int> um;
        
        for(int x : arr)
            um[x]++;
        
        vector<pair<int, int>> v;
        
        copy(um.begin(), um.end(), back_inserter<vector<pair<int,int>>>(v));
        
        sort(v.begin(), v.end(), [](const pair<int,int> &l, pair<int,int> &r)
             {
                 if(l.second != r.second)
                     return l.second>r.second;
                 
                 return l.first<l.second;
             });
        
        int half = (arr.size()/2);
        int currentSize = 0, elements = 0;
        
        for(auto x : v)
        {
            currentSize += x.second;
            elements++;
            if(currentSize >= half)
                break;
        }
        
        return elements;
            
        
    }
};