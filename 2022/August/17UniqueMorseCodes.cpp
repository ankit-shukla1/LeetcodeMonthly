// Problem Link : https://leetcode.com/problems/unique-morse-code-words/

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> us;
        
        for(auto word : words)
        {
            string s = "";
            for(char c : word)
            {
                s += codes[c-'a'];
            }
            us.insert(s);
        }
        
        return us.size();
    }
};