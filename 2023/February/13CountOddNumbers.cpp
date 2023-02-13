// Problem Link : https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/

class Solution {
public:
    int countOdds(int low, int high) {

        if(low%2 == 0 and high%2 == 0){
            return ((high-low)/2);
        }else{
            return ((high-low)/2)+1;
        }
        
    }
};