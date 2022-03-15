#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;
        while (l <= r){
            if(nums[l] <= nums[r]) return nums[l];
            
            mid = l + ((r - l) >> 1);
            
            if(nums[l] <= nums[mid]) l = mid+1;
            else if(nums[l] > nums[mid]) r = mid;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    cout << solution.findMin(nums) << endl;
    return 0;
}