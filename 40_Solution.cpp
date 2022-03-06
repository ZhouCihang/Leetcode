#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int> > result;
    vector<int> path;
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
    {
        vector<bool> used(candidates.size(), false);
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, path, used, target, 0, 0);
        return result;
    }
    void backtracking(vector<int> &candidates, vector<int> &path, vector<bool> &used, int target, int start, int sum)
    {
        if (sum == target)
        {
            result.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); i++)
        {
            if (candidates[i] == candidates[i - 1] && i > 0 && used[i - 1] == false)
            {
                continue;
            }
            if (used[i] == false)
            {
                used[i] = true;
                path.push_back(candidates[i]);
                backtracking(candidates, path, used, target, i + 1, sum + candidates[i]);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > result;
    vector<int> candidates{10, 1, 2, 7, 6, 1, 5};
    result = solution.combinationSum2(candidates, 8);

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