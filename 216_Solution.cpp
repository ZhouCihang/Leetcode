#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int> > result;
    vector<vector<int> > combinationSum3(int k, int n)
    {
        vector<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> path;
        backtracking(nums, path, k, n, 0);
        return result;
    }
    void backtracking(vector<int> &nums, vector<int> &path, int k, int target, int start)
    {
        if (path.size() == k && target == 0)
        {
            result.push_back(path);
            return;
        }
        for (int i = start; i < nums.size(); i++)
        {
            if (nums[i] > target)
                break;

            path.push_back(nums[i]);
            backtracking(nums, path, k, target - nums[i], i + 1);
            path.pop_back();
        }
    }
};

int main()
{
    vector<vector<int> > result;
    Solution solution;
    result = solution.combinationSum3(3, 9);

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}