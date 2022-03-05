#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int> > res;
    vector<vector<int> > subsetsWithDup(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> path;
        backtracking(nums, path, 0);
        return res;
    }

    void backtracking(vector<int> &nums, vector<int> &path, int start)
    {
        res.push_back(path);
        for (int i = start; i < nums.size(); i++)
        {
            if (i > start && nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                path.push_back(nums[i]);
                backtracking(nums, path, i + 1);
                path.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int> > result;
    vector<int> nums{1, 2, 2};
    result = s.subsetsWithDup(nums);

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