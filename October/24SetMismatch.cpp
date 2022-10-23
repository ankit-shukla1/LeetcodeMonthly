// Problem Link : https://leetcode.com/problems/set-mismatch/description/

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int n = nums.size();

        vector<int> hash(n+1, 0);
        vector<int> result(2,0);

        for(int i=0; i<n; i++){
            hash[nums[i]]++;
        }

        for(int i=1; i<n+1; i++){
            if(hash[i] == 2)
                result[0] = i;
            if(hash[i] == 0)
                result[1] = i;
        }

        return result;
        
    }
};