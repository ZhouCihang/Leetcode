#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, mid;
        vector<int> result(2, -1);

        while (left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
            else{
                if(mid == left || nums[mid] != nums[mid-1]){
                    result[0] = mid;
                    break;
                }else{
                    right = mid - 1;
                    result[0] = mid - 1;
                }
            }
        }

        left = 0, right = nums.size() - 1;
        while(left <= right){
            mid = left + (right - left) / 2;
            if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
            else{
                if(mid == right || nums[mid] != nums[mid+1]){
                    result[1] = mid;
                    break;
                }else{
                    left = mid + 1;
                    result[1] = mid + 1;
                }
            }
        }
        return result;
    }

    int lowerBound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] < target) left = mid + 1;
            else if(nums[mid] >= target) right = mid - 1;
        }
        return left;
    }

    int upperBound(vector<int>& nums, int target){
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if(nums[mid] <= target) left = mid + 1;
            else if(nums[mid] > target) right = mid - 1;
        }
        return right;
    }
    vector<int> searchRange2(vector<int>& nums, int target) {
        int upper = upperBound(nums, target);
        int lower = lowerBound(nums, target);
        vector<int> result(2, -1);
        
        if(upper < lower) return result;
        result[0] = lower, result[1] = upper;
        return result;
    }
};
/*????????????????????????????????????????????????????????????

???????????????????????? target <= nums[mid] ??????right = mid -1???target > nums[mid] ??????left = mid + 1???

???????????????????????? target < nums[mid] ??????right = mid -1; target >= nums[mid] ??? left = mid + 1;????????????????????????????????????????????????right???
*/
// Do you have Project management experience demonstrating effective communication, teamwork skills, problem solving, and multiple concurrent project workload management?


int main(){
    Solution s;
    vector<int> nums{5,7,7,8,8,10};
    vector<int> result;
    result = s.searchRange2(nums, 8);
    return 0;
} 