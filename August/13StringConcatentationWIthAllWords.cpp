// Problem Link : https://leetcode.com/problems/substring-with-concatenation-of-all-words/

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<int>result;
        int wordLength = words[0].size();
        unordered_map<string, int> cm;
        
        for(auto word : words)
            cm[word]++;
        
        for(int i=0; i<s.size() - (words.size()*wordLength-1); i++)
        {
            unordered_map<string, int> um;
            int index = i;
            bool flag = true;
            for(int j=0; j<words.size(); j++)
            {
                string temp = s.substr(index, wordLength);
                
                if( cm.find(temp) != cm.end())
                {
                    um[temp]++;
                    index = index + wordLength;

                    if( um[temp] > cm[temp])
                    {
                        flag = false;
                        break;
                    }
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            
            if( flag )
                result.push_back(i);       
            
        }
        
        return result;
        
    }
};