// Problem Link : https://leetcode.com/problems/binary-trees-with-factors/

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {

        int mod = pow(10, 9) + 7;
        sort(arr.begin(), arr.end());
        unordered_map<int, long> um;
        um[arr[0]] = 1;

        for (int i = 1; i < arr.size(); i++)
        {
            long count = 1;
            for (auto j : um)
            {
                int ele = j.first;

                if (arr[i] % ele == 0 and um.find(arr[i] / ele) != um.end())
                {
                    count += um[ele] * um[arr[i] / ele];
                }
            }

            um[arr[i]] = count;
        }

        long result = 0;

        for (auto x : um)
        {
            result = ((result % mod) + (x.second % mod)) % mod;
        }

        return result;
    }
};