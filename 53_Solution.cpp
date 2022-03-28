#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int sum = 0;
        int maxResult = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); ++i){
            sum += nums[i];
            while (sum < 0){
                sum -= nums[left++];
            }
            maxResult = max(sum, maxResult);
        }
        int maxVal = nums[0];
        for(int i = 1; i< nums.size(); ++i){
            maxVal = max(maxVal, nums[i]);
        }
        return maxVal < 0 ? maxVal : maxResult;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}