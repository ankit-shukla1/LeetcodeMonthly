// Problem Link : https://leetcode.com/problems/delete-columns-to-make-sorted/description/


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int n = strs.size();

        if(n==1)
            return 0;
        
        int len = strs[0].size();
        int ans = 0;

        for(int i=0; i<len; i++){
            for(int j=1; j<n; j++){
                if( strs[j][i] < strs[j-1][i])
                {
                    ans++;
                    break;
                }
            }
        }

        return ans;
        
    }
};