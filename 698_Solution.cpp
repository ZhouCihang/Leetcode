#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int sum = 0, avg = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        avg = sum / k;

        vector<bool> used(nums.size(), false);
        return backtracking(nums, used, avg, 0, 0, k);
    }
    bool backtracking(vector<int> &nums, vector<bool> &used, int target, int currSum, int start, int k){
        if(k ==0) return true;
        if(currSum == target) return backtracking(nums, used, target, 0, 0, k-1);
        for(int i = start; i < nums.size(); i++){
            if(used[i] || currSum + nums[i] > target){
                cout << " sum: " << currSum + nums[i] << endl;
                cout << used[i] <<" haha "<< endl;
                continue;
            } 

            used[i] = true;
            if(backtracking(nums, used, target, currSum + nums[i], i + 1, k)) return true;
            used[i] = false;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums{4, 3, 2, 3, 5, 2, 1};
    cout << s.canPartitionKSubsets(nums, 4) << endl;
    return 0;
}