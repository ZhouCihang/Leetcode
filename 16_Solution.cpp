#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < nums.size() - 2; ++i){
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(abs(sum - target) < abs(result - target)){
                    result = sum;
                }
                if(sum > target){
                    right--;
                }else if(sum < target){
                    left++;
                }else return target;
                
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{-1, 2, 1, -4};
    cout << solution.threeSumClosest(nums, 1);
    return 0;
}