#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        vector<int> res(A.size());
        int l = 0, r = A.size() - 1;
        for (int k = A.size() - 1; k >= 0; k--)
        {
            if (abs(A[r]) > abs(A[l]))
            {
                res[k] = A[r] * A[r];
                r--;
            }
            else
            {
                res[k] = A[l] * A[l];
                l++;
            }
        }
        return res;
    }
};

void test()
{
    Solution solution;
    vector<int> nums{-4, -1, 0, 3, 10};
    vector<int> result;

    result = solution.sortedSquares(nums);
}

int main()
{
    test();
    return 0;
}