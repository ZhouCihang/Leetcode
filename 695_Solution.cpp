#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int> > &grid)
    {
        int ans = 0, res = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                ans = isIslandDFS(grid, i, j);
                res = max(res, ans);
                ans = 0;
            }
        }
        return res;
    }
    int isIslandDFS(vector<vector<int> > &grid, int i, int j)
    {
        if (i < grid.size() && i >= 0 && j < grid[0].size() && j >= 0)
        {
            if (grid[i][j] == 0)
                return 0;
            else
            {
                grid[i][j] = 0;
                return 1 + isIslandDFS(grid, i - 1, j) +
                       isIslandDFS(grid, i + 1, j) +
                       isIslandDFS(grid, i, j - 1) +
                       isIslandDFS(grid, i, j + 1);
            }
        }
        else{
            return 0;
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int> > grid{{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0},
                              {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    cout << s.maxAreaOfIsland(grid) << endl;
    return 0;
}