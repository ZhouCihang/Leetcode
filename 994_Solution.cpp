#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

public:
    int orangesRotting(vector<vector<int> > &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int> > dist(m, vector<int>(n));
        vector<vector<int> > seen(m, vector<int>(n));
        queue<pair<int, int> > q;

        int fresh = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int step = -1;
        while (!q.empty())
        {
            int cur = q.size();
            while (cur--)
            {
                auto [i, j] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++)
                {
                    int ni = i + dirs[d][0];
                    int nj = j + dirs[d][1];
                    if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj] && grid[ni][nj] == 1)
                    {
                        grid[ni][nj] = 2;
                        q.emplace(ni, nj);
                        fresh--;
                        seen[ni][nj] = 1;
                    }
                }
            }
            step++;
        }
        if(fresh > 0) return -1;
        if(step == -1) return 0;
        return step;
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > grid{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << solution.orangesRotting(grid) << endl;
    return 0;
}