#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int closedIsland(vector<vector<int> > &grid)
    {
        int result = 0;
        int m = grid.size(), n = grid[0].size();

        // first and last row
        for (int j = 0; j < n; j++)
        {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }

        //// first and last column
        for (int i = 0; i < m; i++)
        {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 0)
                {
                    result += 1;
                    dfs(grid, i, j);
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<int> > &grid, int i, int j)
    {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size())
        {
            return;
        }
        if (grid[i][j] == 1)
            return;
        grid[i][j] = 1;
        dfs(grid, i - 1, j);
        dfs(grid, i + 1, j);
        dfs(grid, i, j - 1);
        dfs(grid, i, j + 1);
    }
};

int main()
{
    Solution s;
    vector<vector<int> > grid{{0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 1, 1, 1, 1, 1, 0},
                              {0, 1, 0, 1, 0, 0, 1, 0},
                              {0, 1, 1, 1, 1, 1, 1, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0}};
    cout << s.closedIsland(grid);
    return 0;
}