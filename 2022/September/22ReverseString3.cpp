// Problem Link : https://leetcode.com/problems/reverse-words-in-a-string-iii/


class Solution {
public:
    string reverseWords(string s) {
        
        string result = "";
        
        string temp = "";
        
        for(char c : s)
        {
            if(c == ' ')
            {
                reverse(temp.begin(), temp.end());
                result += temp;
                temp = "";
                result += " ";
            }
            else
            {
                temp += c;
            }
        }
        
        reverse(temp.begin(), temp.end());
        
        result += temp;
        
        return result;
        
    }
};