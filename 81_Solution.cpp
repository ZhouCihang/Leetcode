#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid;

        while (left <= right)
        {
            mid = left + ((right - left) >> 1);
            if (target == nums[mid])
                return true;

            if (nums[mid] >= nums[left])
            {
                if(nums[mid] > target && target >= nums[left]){
                    right--;
                }else if(nums[mid] < target || target < nums[left]){
                    left++;
                }
            }else{
                if(nums[mid] < target && target <= nums[right]){
                    left++;
                }else if(nums[mid] > target || target > nums[right]){
                    right--;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums{1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    cout << s.search(nums, 2);
    return 0;
}