#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> preSum(n + 1);
        preSum[0] = 0;
        for (int i = 0; i < n; i++)
        {
            preSum[i + 1] = preSum[i] + nums[i];
        }

        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if ((preSum[i] - preSum[j]) == k)
                {
                    count++;
                }
            }
        }
        return count;
    }

    int subarraySumMethod2(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> preSum(n + 1);
        preSum[0] = 1;

        int ans = 0, sum0_i = 0;
        for(int i = 0; i<n; i++){
            sum0_i += nums[i];
            
            int sum0_j = sum0_i - k;
            if(preSum.count(sum0_j)){
                ans += preSum[sum0_j];
            }
            preSum[sum0_i]++;
        }
        return ans;
    }
};

void test()
{
    Solution solution;
    vector<int> nums{1, 2, 3};
    cout << solution.subarraySumMethod2(nums, 2) << endl;
}

int main()
{
    test();
    return 0;
}