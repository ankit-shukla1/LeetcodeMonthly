// Problem Link : https://leetcode.com/problems/longest-increasing-subsequence/

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {

        int ans = INT_MIN;
        vector<int> LIS(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            LIS[i] = 1;

            for (int j = i; j >= 0; j--)
            {
                if (nums[i] > nums[j])
                    LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
            ans = max(ans, LIS[i]);
        }

        return ans;
    }
};