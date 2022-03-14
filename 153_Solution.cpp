#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1, mid;
        while (l < r){
            mid = l + (r - l) / 2;
            if(nums[l] < nums[r]) return nums[l];
            else if(nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        return nums[l];
    }
};

int main()
{
    Solution solution;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    cout << solution.findMin(nums) << endl;
    return 0;
}