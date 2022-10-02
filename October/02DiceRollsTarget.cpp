// Problem Link : https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/


class Solution {
public:
    
    int k;
    int dp[31][1001];
    int mod = 1e9+7;
    int ways(int n,int tar)
    {
        if(n<0)
            return 0;
        if(tar == 0)
            return n == 0;
        if(dp[n][tar] != -1)
            return dp[n][tar];
        int ans = 0;
        for(int i = 1;i<=k;i++)
        {
            if(tar - i >= 0)
                ans = (0ll+ans+ways(n-1,tar-i))%mod;
        }
        return dp[n][tar] = ans;
    }
    
    int numRollsToTarget(int n, int k, int target) {
        this->k = k;
        memset(dp,-1,sizeof(dp));
        return ways(n,target);
    }
};