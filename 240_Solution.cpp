#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        if (!matrix.size() || !matrix[0].size())
            return false;

        for (int row = 0; row < matrix.size(); row++)
        {
            int left = 0, right = matrix[row].size() - 1, mid;
            while (left <= right)
            {
                mid = left + ((right - left) >> 1);
                if (matrix[row][mid] == target)
                    return true;
                else if (matrix[row][mid] < target)
                    left = mid + 1;
                else if (matrix[row][mid] > target)
                    right = mid - 1;
            }
        }
        return false;
    }

    bool searchMatrixZ(vector<vector<int> > &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int x = 0, y = n - 1;
        while (x < m && y >= 0)
        {
            if (matrix[x][y] == target)
            {
                return true;
            }
            if (matrix[x][y] > target)
            {
                --y;
            }
            else
            {
                ++x;
            }
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > matrix{{1, 4, 7, 11, 15},
                                {2, 5, 8, 12, 19},
                                {3, 6, 9, 16, 22},
                                {10, 13, 14, 17, 24},
                                {18, 21, 23, 26, 30}};

    vector<vector<int> > matrix1{{-1, 3}};
    cout << solution.searchMatrix(matrix, 3);
    return 0;
}