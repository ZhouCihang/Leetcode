#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int search(vector<int>& nums, int target) {

        if(nums.size() == 1 && nums[0] == target){
            return 0;
        }

        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if(nums[mid] == target){
                return mid;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }
        return -1;
    }
};

void test(){
    Solution solution;
    vector<int> nums{2,5};
    cout << solution.search(nums, 5) << endl;
}

int main(){
    test();
    return 0;
}