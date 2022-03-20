#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int row = grid2.size(), col = grid2[0].size();
        int result = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if(grid1[i][j] == 0 && grid2[i][j] == 1){
                    dfs(grid2, i, j);
                }
            }
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if(grid2[i][j] == 1){
                    result++;
                    dfs(grid2, i, j);
                }
            }
        }
        return result;
    }
    void dfs(vector<vector<int> > &grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()){
            return;
        }
        if(grid[i][j] == 0) return;
        grid[i][j] = 0;
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};

int main()
{
    Solution s;
    vector<vector<int> > grid1{{1,1,1,0,0}, {0,1,1,1,1}, {0,0,0,0,0}, {1,0,0,0,0}, {1,1,0,1,1}};
    vector<vector<int> > grid2{{1,1,1,0,0}, {0,0,1,1,1}, {0,1,0,0,0}, {1,0,1,1,0}, {0,1,0,1,0}};
    cout<< s.countSubIslands(grid1, grid2)<<endl;
    return 0;
}