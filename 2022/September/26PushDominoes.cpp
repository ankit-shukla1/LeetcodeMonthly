// Problem Link : https://leetcode.com/problems/push-dominoes/ 

class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.size();
        
        vector<int> leftD(n,0);
        vector<int> rightD(n,0);
        int lastLeft = -1, lastRight=-1;
        
        // for filling the rightD array
        
        for(int i=0; i<n; i++){
            if(dominoes[i] == '.')
            {
                if(lastRight==-1)
                    rightD[i] = INT_MAX;
                else
                    rightD[i] = i - lastRight;
            }
            else if(dominoes[i] == 'L')
                lastRight=-1;
            else
                lastRight=i;
        }
        
        // for filling the leftD array
        
        for(int i=n-1; i>=0; i--){
            if(dominoes[i] == '.')
            {
                if(lastLeft==-1)
                    leftD[i] = INT_MAX;
                else
                    leftD[i] = lastLeft-i;
            }
            else if(dominoes[i] == 'R')
                lastLeft=-1;
            else
                lastLeft=i;
        }
        
        for(int i=0; i<n; i++)
        {
            if(dominoes[i] == '.')
            {
                if(leftD[i] != rightD[i])
                {
                    if(leftD[i] < rightD[i])
                        dominoes[i] = 'L';
                    else
                        dominoes[i] = 'R';
                }
            }
        }
        
        return dominoes;
        
    }
};