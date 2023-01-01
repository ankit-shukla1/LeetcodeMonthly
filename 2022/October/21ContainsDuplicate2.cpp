// Problem Link :   https://leetcode.com/problems/contains-duplicate-ii/description/


class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        if(k==0)
            return false;

        int n = nums.size();
        unordered_map<int, int> um;
        for(int i=0; i<n; i++)
        {
            if(um.find(nums[i]) != um.end())
            {
                if( (i - um[nums[i]] ) <= k)
                {
                    return true;
                }
                else
                    um[nums[i]] = i;

            }
            else{
                um[nums[i]] = i;
            }

        }

        return false;
        
    }
};