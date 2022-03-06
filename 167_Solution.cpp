#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            if (sum == target)
                return {i + 1, j + 1};
            else if (sum > target)
                j--;
            else
                i++;
        }
        return {}; // not found
    }
};

void test()
{
    Solution solution;
    vector<int> numbers{2, 7, 11, 15};
    vector<int> result;
    result = solution.twoSum(numbers, 26);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}