#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

void printVector(vector<int> &list)
{
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

class Solution
{
public:
    vector<vector<int> > diagonalSort2(vector<vector<int> > &mat)
    {
        int col = mat[0].size();
        int row = mat.size();
        vector<vector<int> > colums(col);
        vector<vector<int> > rows(row);

        for (int i = 0; i < col; i++)
        {
            for (int j = 0; j < row; j++)
            {
                colums[i].push_back(mat[j][i]);
            }
            sort(colums[i].begin(), colums[i].end());
            printVector(colums[i]);
        }

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                rows[i].push_back(colums[j][i]);
            }
            sort(rows[i].begin(), rows[i].end());
            printVector(rows[i]);
        }

        return rows;
    }

    void solve(int i, int j, vector<vector<int> > &mat)
    {
        vector<int> hey;
        int ti = i, tj = j;
        while (ti < mat.size() && tj < mat[0].size())
        {
            hey.push_back(mat[ti][tj]);
            ti++;
            tj++;
        }
        sort(hey.begin(), hey.end());
        for (auto x : hey)
        {
            mat[i][j] = x;
            i++;
            j++;
        }
    }

    vector<vector<int> > diagonalSort(vector<vector<int> > &mat)
    {
        if (mat.size() == 1 || mat[0].size() == 1)
            return mat;

        for (int i = 0; i < mat[0].size(); i++)
        {
            solve(0, i, mat);
        }
        for(int i=1;i<mat.size();i++)
        {
            solve(i,0,mat);
        }
        return mat;
    }
};

void test()
{
    Solution solution;
    vector<vector<int> > mat{{11, 25, 66, 1, 69, 7}, {23, 55, 17, 45, 15, 52}, {75, 31, 36, 44, 58, 8}, {22, 27, 33, 25, 68, 4}, {84, 28, 14, 11, 5, 50}};
    vector<vector<int> > res;

    res = solution.diagonalSort(mat);
}

int main()
{
    test();
    return 0;
}