#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int res = INT_MIN;

        sort(begin(nums), end(nums));
        for (auto i = 0; i < nums.size() / 2; ++i)
            res = max(res, nums[i] + nums[nums.size() - i - 1]);
        return res;
    }
};

void test()
{
    Solution solution;
    vector<int> nums{3, 5, 2, 3};
    cout << solution.minPairSum(nums) << endl;
}

int main()
{
    test();
    return 0;
}