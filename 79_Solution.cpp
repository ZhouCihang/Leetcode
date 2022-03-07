#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    bool exist(vector<vector<char> > &board, string word)
    {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int> > visited(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag)
                    return true;
            }
        }
        return false;
    }
    bool check(vector<vector<char> > &board, vector<vector<int> > &visited,
               int i, int j, string &word, int k)
    {
        if (board[i][j] != word[k])
            return false;
        else if (k == word.length() - 1)
            return true;

        visited[i][j] = true;
        vector<pair<int, int> > directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (auto &dir : directions)
        {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size())
            {
                if(!visited[newi][newj]){
                    bool flag = check(board, visited, newi, newj, word, k + 1);
                    if(flag){
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<char> > board{{'A','B','C','E'},{'S','F','C','S'}, {'A','D','E','E'}};
    cout << s.exist(board, "ABCB") << endl;
    return 0;
}