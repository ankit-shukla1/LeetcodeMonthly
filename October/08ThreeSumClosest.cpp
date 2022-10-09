// Problem Link : https://leetcode.com/problems/3sum-closest/description/

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int diff = INT_MAX;

        int n = nums.size();
        int result = 0;
        int currSum=0;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-2; i++){
                int j = i+1;
                int k = nums.size()-1;

                while(j<k){
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == target)
                        return sum;
                    else if(sum < target){
                        j++;
                    }
                    else{
                        k--;
                    }
                    if(diff > abs(sum - target)){
                        diff = abs(sum -target);
                        result = sum;
                    }
                }
        }

        return result;
        
    }
};