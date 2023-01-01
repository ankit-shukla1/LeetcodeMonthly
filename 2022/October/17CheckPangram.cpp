// Problem Link : https://leetcode.com/problems/check-if-the-sentence-is-pangram/description/


class Solution {
public:
    bool checkIfPangram(string sentence) {

        int hash[26];

        for(int i=0; i<25; i++)
            hash[i]=0;

        for(int i=0; i<sentence.size(); i++)
            hash[sentence[i]-'a']++;
        
        for(int i=0; i<26; i++)
            if(hash[i] == 0)
                return false;

        return true;
        
    }
};