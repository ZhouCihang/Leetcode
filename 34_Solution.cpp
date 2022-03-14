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
};

int main(){
    Solution s;
    vector<int> nums{5,7,7,8,8,10};
    vector<int> result;
    result = s.searchRange(nums, 8);
    return 0;
} 