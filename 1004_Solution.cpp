//1:54 pm
#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<int> zeroIndex;

    int countOnes(vector<int> &nums)
    {
        int countOne = 0, maxOne = 0;
        bool ones = true;

        for (int i = 0; i < nums.size(); i++)
        {
            ones *= nums[i];

            if (!ones)
            {
                countOne = 0;
                ones = true;
                zeroIndex.push_back(i);
            }
            else
            {
                countOne++;
            }
            maxOne = max(maxOne, countOne);
        }
        return maxOne;
    }

    int countZeros(vector<int> &nums)
    {
        int countZero = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 0)
                countZero++;
        }
        return countZero;
    }

    int longestOnes(vector<int> &nums, int k)
    {
        //find any [left, right] contain less or equal than k zeros
        int n = nums.size();
        vector<int> preSum(n+1);
        preSum[0] = 0;

        //return number of zero in the sub section
        for(int i = 0; i < n; i++){
            preSum[i+1] = preSum[i] + (1 - nums[i]);
        }

        int ans = 0;
        for(int right = 0; right < n; right++){
            int left = lower_bound(preSum.begin(), preSum.end(), preSum[right+1]-k) - preSum.begin();
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

void test()
{
    Solution solution;
    vector<int> nums{1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << solution.longestOnes(nums, 2) << endl;
}

int main()
{
    test();
    return 0;
}