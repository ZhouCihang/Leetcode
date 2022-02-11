#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int index = nums.size();
        return nums[index -1] * nums[index-2] -  nums[1] * nums[0];
    }
};

void test(){
    Solution solution;
    vector<int> nums{5, 6, 2, 7, 4};
    cout << solution.maxProductDifference(nums) << endl;
}

int main(){
    test();
    return 0;
}