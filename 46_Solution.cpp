#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void print(const vector<vector<int>> &v)
    {
        for (int i = 0; i < v.size(); i++){
            for (int j = 0; j < v[i].size(); j++){
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
};

void test()
{
    Solution solution;
    vector<int> nums{0, -1, 1};
    vector<vector<int> > result;
    result = solution.permute(nums);
}

int main()
{
    test();
    return 0;
}