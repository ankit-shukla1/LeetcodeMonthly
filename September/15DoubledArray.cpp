// Problem Link :  https://leetcode.com/problems/find-original-array-from-doubled-array/

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        int n = changed.size();
        
        vector<int> result;
        
        if(n%2 != 0)
            return result;
        
        unordered_map<int, int> um;
        for(int i=0; i<n; i++)
        {
            um[changed[i]]++;
        }
        
        vector<int> temp;
        sort(changed.begin(), changed.end());
        
        for(int i=0; i<n; i++)
        {
            if(changed[i] == 0)
            {
                if(um[changed[i]]>=2)
                {
                    temp.push_back(0);
                    um[changed[i]]-=2;
                    if(um[changed[i]]==0)
                        um.erase(changed[i]);
                }
            }
            else
            {
                if(um.find(changed[i]) != um.end() and um.find(changed[i]*2) != um.end())
                {
                    temp.push_back(changed[i]);
                    um[changed[i]]--;
                    um[changed[i]*2]--;
                    
                    if(um[changed[i]] == 0)
                        um.erase(changed[i]);
                    if(um[changed[i]*2] == 0)
                        um.erase(changed[i]*2);
                }
            }
        }
        
        
        if(temp.size() == (n/2))
            return temp;
        else
        {
            temp.clear();
            return temp;
        }
        
    }
};