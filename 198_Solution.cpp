#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:

    int solve(vector<int> &nums, int idx, vector<int> &dp){
        if(idx >= nums.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        return dp[idx] = max(nums[idx] + solve(nums, idx+2, dp), solve(nums, idx+1, dp));
    }

    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return solve(nums, 0, dp);
    }
};

int main(){

    Solution s;
    vector<int> nums{2, 7, 9, 3, 1};
    cout<<s.rob(nums)<<endl;

    return 0;
}