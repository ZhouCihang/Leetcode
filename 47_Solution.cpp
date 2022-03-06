#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int> > result;
    vector<int> path;
    vector<vector<int> > permuteUnique(vector<int> &nums)
    { 
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        backtrack(nums, used, path);
        return result;
    }
    void backtrack(vector<int> &nums, vector<bool> &used, vector<int> &path)
    {
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1] && used[i - 1] == false){
                continue;
            }
            if(used[i] == false){
                used[i] = true;
                path.push_back(nums[i]);
                backtrack(nums, used, path);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};

int main()
{
    Solution sl;
    vector<int> nums{1, 1, 2};
    vector<vector<int> > result;
    result = sl.permuteUnique(nums);

    cout << "size: " << result.size() << endl;
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