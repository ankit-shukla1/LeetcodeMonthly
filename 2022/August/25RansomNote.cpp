// Problem Link : https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char, int> um;
        
        for(char ch : magazine)
            um[ch]++;
        
        for(char ch : ransomNote)
        {
            if(um.find(ch) == um.end())
                return false;
            else if(um[ch] <=0 )
                return false;
            else
                um[ch]--;
        }
        
        return true;
    }
};