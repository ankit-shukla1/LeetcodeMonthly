// Problem Link : https://leetcode.com/problems/sort-the-matrix-diagonally/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        
        int rowSize = mat.size();
        int columnSize = mat[0].size();
        
        for(int i=0; i<rowSize; i++)
        {
            int r=i, c=0;
            vector<int> temp;
            while(r<rowSize and c<columnSize)
            {
                temp.push_back(mat[r][c]);
                r++;c++;
            }
            sort(temp.begin(), temp.end());
            int k=0;
            r=i, c=0;
            while(r<rowSize and c<columnSize)
            {
                mat[r][c] = temp[k];
                r++;c++;k++;
            }
        }
        
        for(int i=1; i<columnSize; i++)
        {
            int r=0, c=i;
            vector<int> temp;
            while(r<rowSize and c<columnSize)
            {
                temp.push_back(mat[r][c]);
                r++;c++;
            }
            sort(temp.begin(), temp.end());
            int k=0;
            r=0, c=i;
            while(r<rowSize and c<columnSize)
            {
                mat[r][c] = temp[k];
                r++;c++;k++;
            }
        }
        
        return mat;
        
    }
};