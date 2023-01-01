// Problem Link : https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

class Solution
{

private:
    int countSmaller(vector<vector<int>> &a, int k)
    {
        int n = a.size();
        int count = 0;

        int i = 0, j = n - 1;

        while (i < n && j >= 0)
        {
            if (a[i][j] > k)
                j--;
            else
            {
                count += (j + 1);
                i++;
            }
        }

        return count;
    }

public:
    int kthSmallest(vector<vector<int>> &a, int k)
    {

        int result = -1;
        int low = a[0][0], high = a[a.size() - 1][a.size() - 1];

        while (low <= high)
        {
            int mid = low + ((high - low) >> 1);

            if (countSmaller(a, mid) >= k)
            {
                result = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }

        return result;
    }
};