// Problem Link : https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/


class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {

        int n = nums.size();
        int m = queries.size();

        sort(nums.begin(), nums.end());

        for(int i=1; i<n; i++){
            nums[i] = nums[i] + nums[i-1];
        }
        vector<int> result(m,0);
        int j;
        for(int i=0; i<m; i++){
            for(j=0; j<n; j++){
                if(nums[j] > queries[i])
                    break;
            }

            result[i] = j;
        }

        return result;
        
    }
};