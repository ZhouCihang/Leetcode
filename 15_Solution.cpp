#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int> > threeSum(vector<int> &nums)
    {
        vector<vector<int> > result;
        sort(nums.begin(), nums.end());
        if (nums.size() < 3 || nums[0] > 0)
            return {};
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = nums.size() - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum == 0)
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    int lastLowOccurence =nums[left];
                    int lasthighOccurence =nums[right];
                    while(left< right && nums[left] == lastLowOccurence){
                        left++;
                    }
                    while(left< right && nums[right] == lasthighOccurence){
                        right--;
                    }
                }
                else if (sum > 0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return result;
    }
};

int main()
{
    vector<vector<int> > result;
    Solution solution;
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    result = solution.threeSum(nums);
    for(int i=0; i<result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}