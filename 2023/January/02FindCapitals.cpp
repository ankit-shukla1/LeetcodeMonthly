// Problem Link : https://leetcode.com/problems/detect-capital/description/

class Solution {
public:
    bool detectCapitalUse(string word) {

        int countCapitals = 0;

        for(char c : word ){
            if(isupper(c))
                countCapitals++;
        }

        return (countCapitals == 0) || (countCapitals == word.size()) || (countCapitals == 1 && isupper(word[0]));
        
    }
};