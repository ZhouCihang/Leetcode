#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        int row = grid.size(), col = grid[0].size();
        for(int i = 0; i < row; i++){
            dfs(grid, i, 0);
            dfs(grid, i, col - 1);
        }
        for(int j = 0; j < col; j++){
            dfs(grid, 0, j);
            dfs(grid, row - 1, j);
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(grid[i][j] == 1){
                    res++;
                    //dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<int>>& grid, int i, int j){
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return;
        if(grid[i][j] == 0) return;
        grid[i][j] = 0;
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid{{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
    cout << s.numEnclaves(grid) << endl;
    return 0; 
}