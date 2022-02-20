#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;

        while (left <= right){
            int mid = left + (right - left) / 2;
            if (target == nums[mid]){
                return mid;
            }else if (nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        
        return left;
    }
};

void test()
{
    Solution solution;
    vector<int> nums{1, 3, 5, 6};
    cout << solution.searchInsert(nums, 7) << endl;
}

int main()
{
    test();
    return 0;
}