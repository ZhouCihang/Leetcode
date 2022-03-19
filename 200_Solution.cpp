#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
public:
    int numIslands(vector<vector<char> > &grid)
    {
        int result = 0;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    result += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<char> > &grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};

int main()
{
    Solution s;
    vector<vector<char> > grid{{'1', '1', '1', '1', '0'},
                               {'1', '1', '0', '1', '0'},
                               {'1', '1', '0', '0', '0'},
                               {'0', '0', '0', '0', '0'}};
    cout << s.numIslands(grid) << endl;
    return 0;
}