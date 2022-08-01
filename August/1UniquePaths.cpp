// Problem Link : https://leetcode.com/problems/unique-paths/

class Solution
{
public:
    int uniquePaths(int m, int n)
    {

        int c = n + m - 2;
        int r = min(n, m) - 1;

        // now calculate nCr

        long long int result = 1;

        for (int i = 1; i <= r; i++, c--)
        {
            result = (result * c) / i;
        }

        return result;
    }
};