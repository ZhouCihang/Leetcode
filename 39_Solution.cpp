#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int> > result;
    vector<vector<int> > combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        backtracking(candidates, path, target, 0, 0);
        return result;
    }

    //1. find status sum
    void backtracking(vector<int> &candidates, vector<int> &path, int target, int start, int sum)
    {
        //2. find end condition
        if(sum == target){
            result.push_back(path);
            return;
        }

        //3. find selected path
        for (int i = start; i < candidates.size(); i++){

            
            //4. cut extra branch
            if(sum > target){
                continue;
            }

            //5. find selected path
            path.push_back(candidates[i]);
            backtracking(candidates, path, target,i, sum + candidates[i]);

            //6. recall the selection
            path.pop_back();
        }
    }
};

int main()
{
    Solution solution;
    vector<int> candidates{2, 3, 6, 7};
    vector<vector<int> > result;
    result = solution.combinationSum(candidates, 7);

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