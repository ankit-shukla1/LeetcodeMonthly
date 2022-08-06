// Problem Link : https://leetcode.com/problems/poor-pigs/submissions/

class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1)); // log_{T+1}(N)
    }
};