#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            int left = 0, right = i - 1;
            while (left < right)
            {
                int temp = nums[left] + nums[right] - nums[i];
                if (temp > 0){
                    count += right - left;
                    right--;
                }
                else left++;
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{2, 2, 3, 4};
    cout << solution.triangleNumber(nums) << endl;
    return 0;
}