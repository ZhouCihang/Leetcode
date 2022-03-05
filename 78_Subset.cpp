#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void printVector(vector<vector<int> > &result)
    {
        for (int i = 0; i < result.size(); i++)
        {
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printV(vector<int> &result)
    {
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    vector<vector<int> > subsets(vector<int> &nums)
    {
        vector<vector<int> > res;
        vector<int> temp;
        res.push_back(temp);

        for (auto &num : nums)
        {
            vector<vector<int> > newSubsets;
            cout << " num " << num << endl;
            cout << " res size: " << res.size() << endl;
            for (int i = 0; i < res.size(); i++)
            {
                vector<int> newSubset = res[i];
                newSubset.push_back(num);
                printV(newSubset);
                newSubsets.push_back(newSubset);
                cout << " newSubsets size: " << newSubsets.size() << endl;
                //printVector(newSubsets);
            }
            res.insert(res.end(), newSubsets.begin(), newSubsets.end());
            //printVector(newSubsets);
        }
        return res;
    }

    vector<vector<int> > res;

    vector<vector<int> > subsetsBackTracking(vector<int> &nums)
    {   
        vector<int> path;
        res.push_back(path);
        backtracking(nums,path,0);
        return res;
    }

    void backtracking(vector<int> &nums, vector<int> &path, int start)
    {
        res.push_back(path);
        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(nums, path, i + 1);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int> > result;
    vector<int> nums{1, 2, 3};
    result = s.subsetsBackTracking(nums);

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