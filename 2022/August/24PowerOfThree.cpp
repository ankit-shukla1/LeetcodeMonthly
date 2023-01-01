// Problem Link : https://leetcode.com/problems/power-of-three/

class Solution {
public:
    bool isPowerOfThree(int n) {
                if(n<1) return false;
        int c = pow(3,19);
        return c%n==0;
        
    }
};