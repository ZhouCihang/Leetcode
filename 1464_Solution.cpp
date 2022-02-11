#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        sort(nums.begin(), nums.end(), greater<int>());
        return (nums[0] - 1) * (nums[1] - 1);
    }
};

void test(){
    Solution solution;
    vector<int> nums{3, 4, 5, 2};
    cout << solution.maxProduct(nums) << endl;
}

int main(){
    test();
    return 0;
}