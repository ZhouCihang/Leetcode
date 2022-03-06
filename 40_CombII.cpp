#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> path;
        backtracking(candidates, path, target, ans, 0);
        return ans;
    }
    void backtracking(vector<int> &candidates, vector<int> &path, int target, vector<vector<int> > &ans, int start){
        if(target == 0){
            ans.push_back(path);
            return;
        }
        for(int i = start; i<candidates.size(); i++){
            if(candidates[i] > target){
                break;
            }
            if(i > start && candidates[i] == candidates[i-1]){
                continue;
            }
            path.push_back(candidates[i]);
            backtracking(candidates, path, target - candidates[i], ans, i+1);
            path.pop_back();
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