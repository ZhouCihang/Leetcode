#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
    void print(const vector<vector<int> > &v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                cout << " " << v[i][j];
            }
            cout << std::endl;
        }
    }
    vector<vector<int> > permute(vector<int> &nums)
    {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        do
        {
            result.push_back(nums);
        } while (next_permutation(nums.begin(), nums.end()));

        print(result);
        return result;
    }

    vector<vector<int> > result;
    vector<vector<int> > permute2(vector<int> &nums)
    {
        int n = nums.size();
        if (nums.size() == 0)
            return result;

        dfs(nums, 0, n);
        print(result);
        return result;
    }
    void dfs(vector<int> &nums, int depth, int len)
    {
        if (depth == len)
        {
            result.emplace_back(nums);
            return;
        }
        for(int i = depth; i<len; i++){
            swap(nums[i], nums[depth]);
            dfs(nums, depth+1, len);
            swap(nums[i], nums[depth]);
        }
    }
};

void test()
{
    Solution solution;
    vector<int> nums{0, -1, 1};
    vector<vector<int> > result;
    result = solution.permute2(nums);
}

int main()
{
    test();
    return 0;
}