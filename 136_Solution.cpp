#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    //map
    int singleNumber2(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> res;

        for (int i = 0; i < n; i++)
        {
            res[nums[i]]++;
        }

        for (auto &c : res)
        {
            if (c.second == 1)
            {
                return c.first;
            }
        }
        return -1;
    }

    //bitwise
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (auto x : nums)
            ans ^= x;
        return ans;
    }
};

void test()
{
    Solution s;
    vector<int> nums{4, 1, 2, 1, 2};
    cout << s.singleNumber(nums) << endl;
}

int main()
{
    test();
    return 0;
}