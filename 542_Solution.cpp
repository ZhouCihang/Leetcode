#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
public:
    vector<vector<int> > updateMatrix(vector<vector<int> > &mat)
    {
        int m = mat.size(), n = mat[0].size();

        //already visited
        vector<vector<int> > visited(m, vector<int>(n, 0));
        //result matrix
        vector<vector<int> > res(m, vector<int>(n, 0));
        queue<pair<int, int> > q;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    //equal to 1 means already visited
                    visited[i][j] = 1;
                    q.push(pair(i, j));
                }
            }
        }

        while (q.size())
        {
            auto [x, y] = q.front();
            q.pop();
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++)
            {
                int a = x + dx[i];
                int b = y + dx[i];
                if (a >= 0 && a < m && b >= 0 && b < n && visited[a][b] != 1)
                {
                    res[a][b] = res[x][y] + 1;
                    q.push(pair(a, b));
                    visited[a][b] = 1;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > matrix{{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int> > result;
    result = solution.updateMatrix(matrix);

    return 0;
}