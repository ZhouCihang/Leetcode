#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> m;
        for (auto &n : nums)
        {
            m[n]++;
        }

        int count = -1, ans;
        for (auto &i : m)
        {
            if (i.second > nums.size() / 2)
            {
                ans = i.first;
                break;
            }
        }
        return ans;
    }

    int majorityElementMooreAlgo(vector<int> &nums)
    {
        int count = 0;
        int candidates = -1;
        for(auto &n : nums){
            if(count == 0) candidates = n;
            if(n == candidates){
                count++;
            }else{
                count--;
            }
        }
        return candidates;
    }
};

void test()
{
    Solution solution;
    vector<int> nums{2, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 2};
    cout << solution.majorityElement(nums) << endl;
}

int main()
{
    test();
    return 0;
}