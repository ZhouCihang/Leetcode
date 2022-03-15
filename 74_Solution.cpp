#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    bool searchMatrix1(vector<vector<int> > &matrix, int target)
    {

        if (!matrix.size() || !matrix[0].size())
            return false;

        int row = matrix.size(), m = matrix[0].size();
        int left = 0, right = row - 1, mid;

        while (left < right)
        {
            mid = left + (right - left) / 2;
            if (target > matrix[mid].back())
                left = mid + 1;
            else if (target < matrix[mid][0])
                right = mid - 1;
            else
            {
                left = mid;
                break;
            }
        }

        int newLeft = 0, newRight = m - 1, newMid;
        while (newLeft <= newRight)
        {
            newMid = newLeft + (newRight - newLeft) / 2;
            if (target > matrix[left][newMid])
                newLeft = newMid + 1;
            else if (target < matrix[left][newMid])
                newRight = newMid - 1;
            else
                return true;
        }
        return false;
    }

    bool searchMatrix2(vector<vector<int> > &m, int t)
    {
        // pointless edge case we still have to consider
        if (!m.size() || !m[0].size())
            return false;
        // support variables
        int row, l = 0, r = m.size() - 1, mid;
        while (l < r)
        {
            //mid = (l + r) / 2;
            mid = l + (r - l) / 2;
            // moving l up if needed
            if (m[mid].back() < t)
                l = mid + 1;
            // moving r down if needed
            else if (m[mid][0] > t)
                r = mid - 1;
            // we found our row!
            else
            {
                l = mid;
                break;
            }
        }
        // storing the value of the new found row
        row = l;
        // resetting l and r to run a binary search on the rows
        l = 0;
        r = m[0].size() - 1;
        while (l <= r)
        {
            mid = l + (r - l) / 2;
            // moving l up if needed
            if (m[row][mid] < t)
                l = mid + 1;
            // moving r down if needed
            else if (m[row][mid] > t)
                r = mid - 1;
            // we found our value!
            else
                return true;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        if (!matrix.size() || !matrix[0].size())
            return false;

        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row * col - 1, mid;
        while (left <= right)
        {
            mid = left + ((right - left) >> 1);
            int rownum = mid / col;
            int colnum = mid % col;
            if (matrix[rownum][colnum] == target)
                return true;
            else if (matrix[rownum][colnum] < target)
                left = mid + 1;
            else if (matrix[rownum][colnum] > target)
                right = mid - 1;
        }
        return false;
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > matrix{{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    vector<vector<int> > matrix1{{1}};
    cout << solution.searchMatrix(matrix1, 1);
    return 0;
}