#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //key is nums[i], value is i;
        unordered_map<int, int> stored;
        for(int i = 0; i < nums.size(); ++i){
            auto it = stored.find(target - nums[i]);
            if(it != stored.end()) return {i, it->second};
            stored[nums[i]] = i;
        }
        return {};
    }
};

int main()
{
    Solution solution;
    vector<int> nums{2,7,11,15};
    vector<int> result;
    result = solution.twoSum(nums, 9);
    for(int i = 0; i < result.size(); ++i){
        cout << result[i]<<" ";
    }
    cout << endl;
    return 0;
}