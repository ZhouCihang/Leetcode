#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        for (int i = 0; i <= nums.size(); i++)
        {
            int count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i <= nums[j])
                {
                    count++;
                }
            }
            if (count == i)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{3,5};
    cout << solution.specialArray(nums) << endl;
    return 0;
}