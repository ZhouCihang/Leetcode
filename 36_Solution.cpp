#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        // check rows
        for (int i = 0; i < board.size(); ++i)
        {
            unordered_set<char> st;
            for (auto &c : board[i])
            {
                if (c >= '0' && c <= '9')
                {
                    if (st.find(c) != st.end())
                    {
                        return false;
                    }
                    st.insert(c);
                }
            }
            st.clear();
        }

        // check colums
        for (int i = 0; i < board[0].size(); ++i)
        {
            unordered_set<char> st;
            for (int j = 0; j < board[i].size(); ++j)
            {
                if (board[j][i] >= '0' && board[j][i] <= '9')
                {
                    if (st.find(board[j][i]) != st.end())
                        return false;
                    st.insert(board[j][i]);
                }
            }
            st.clear();
        }

        // check for sub boxes
        for (int i = 0; i < board.size(); i++)
        {
            unordered_set<char> st;
            for (int j = i - (i % 3); j < i - (i % 3) + 3; j++)
            {
                for (int k = 3 * (i % 3); k < 3 * (i % 3) + 3; k++)
                {
                    cout<< j << " " << k << " " << " ";
                    if (board[j][k] >= '0' && board[j][k] <= '9')
                    {
                        if (st.find(board[j][k]) != st.end())
                            return false;
                        st.insert(board[j][k]);
                    }
                }
                cout<< endl;
            }
            st.clear();
        }

        return true;
    }
};

int main()
{
    Solution solution;
    vector<vector<char> > board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                   {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                   {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                   {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                   {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                   {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                   {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                   {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                   {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    cout << solution.isValidSudoku(board) << endl;
    return 0;
}