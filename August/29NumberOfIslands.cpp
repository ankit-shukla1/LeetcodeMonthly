// Problem Link : https://leetcode.com/problems/number-of-islands/

class Solution {
public:
void dfs(int r, int c, const vector<pair<int, int>> &direction, vector<vector<char>> &grid, int rowCount, int columnCount)
{
    if (!(r >= 0 && r < rowCount && c >= 0 && c < columnCount && grid[r][c] == '1'))
        return;

    grid[r][c] = '0';
    for (int i = 0; i < int(direction.size()); i++)
    {
        dfs(r + direction[i].first, c + direction[i].second, direction, grid, rowCount, columnCount);
    }
}

int numIslands(vector<vector<char>> &grid)
{
    int rowCount = grid.size();
    int columnCount = grid[0].size();

    // direction vector
    vector<pair<int, int>> direction = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

    int components = 0;
    // traverse through the whole matrix and perform dfs on each component having 1
    for (int i = 0; i < rowCount; i++)
    {
        for (int j = 0; j < columnCount; j++)
        {
            if (grid[i][j] == '1')
            {
                components++;
                dfs(i, j, direction, grid, rowCount, columnCount);
            }
        }
    }
    return components;
}
};