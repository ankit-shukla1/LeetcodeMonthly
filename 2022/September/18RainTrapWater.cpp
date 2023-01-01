// Problem Link : https://leetcode.com/problems/trapping-rain-water/


class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        
        vector<int> leftMax(n, INT_MIN);
        int maxOnLeft = INT_MIN;
        
        for(int i=0; i<n; i++)
        {
            leftMax[i] = max(maxOnLeft, height[i]);
            maxOnLeft = leftMax[i];
            // cout<<leftMax[i]<<" ";
        }
        
        
        vector<int> rightMax(n, INT_MIN);
        int maxOnRight = INT_MIN;
        
        for(int i=n-1; i>=0; i--)
        {
            rightMax[i] = max(maxOnRight, height[i]);
            maxOnRight = rightMax[i];
            // cout<<rightMax[i]<<" ";
        }
        
        int result=0;
        
        for(int i=0; i<n; i++)
        {
            if(height[i] < leftMax[i] and height[i] < rightMax[i])
            {
                result += (min(leftMax[i], rightMax[i]) - height[i]);
            }
        }
        
        return result;
        
        
    }
};