// Problem Link : https://leetcode.com/problems/sort-characters-by-frequency/


class Solution {
public:
    struct comp {
    comp(unordered_map<char, int> um) { this->um = um; }
    bool operator () (char a, char b) {
        if(um[a] == um[b]){
            return a > b;
        }
        return um[a] > um[b];
     }

    unordered_map<char, int> um;
};
    string frequencySort(string s) {

        unordered_map<char, int> um;
        for(int i=0; i<s.size(); i++){
            um[s[i]]++;
        }

        sort(s.begin(), s.end(), comp(um));

        return s;
        
    }
};