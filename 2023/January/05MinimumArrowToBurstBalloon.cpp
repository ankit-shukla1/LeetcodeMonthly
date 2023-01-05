// Problem Link : https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
private:
   static bool comp(vector<int> &a, vector<int> &b){
        if(a[0] == b[0]){
            return (a[1] < b[1]);
        }
        return a[0] < b[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {

        int n = points.size();
        if(n==1)
            return 1;

        // sort the points vector
        sort(points.begin(), points.end(),comp);

        int result = 1;
        int intervalStart = points[0][0], intervalEnd = points[0][1];
        for(int i=1; i<n; i++)
        {
            if( points[i][0] <= intervalEnd and points[i][0] >= intervalStart){
                if(points[i][1] < intervalEnd){
                    intervalEnd = points[i][1];
                }
            }else{
                result++;
                intervalStart = points[i][0];
                intervalEnd = points[i][1];
            }
        }
        return result;
        
    }
};