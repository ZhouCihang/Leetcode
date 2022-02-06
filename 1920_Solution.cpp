#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> buildArray(vector<int> &nums)
    {
        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            res.push_back(nums[nums[i]]);
        }
        return res;
    }
};

void test()
{
    Solution s;
    vector<int> nums{0, 2, 1, 5, 3, 4};
    vector<int> result;
    result = s.buildArray(nums);
}

int main()
{
    test();
    return 0;
}