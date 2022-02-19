#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

class Solution
{
public:
    vector<int> getInterSec(unordered_set<int> &set1, unordered_set<int> &set2)
    {
        if (set1.size() > set2.size())
        {
            return getInterSec(set2, set1);
        }
        vector<int> intSet;
        for (auto &num : set1)
        {
            if (set2.find(num) != set1.end())
            {
                intSet.push_back(num);
            }
        }
        return intSet;
    }

    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> set1, set2;
        vector<int> result;

        for (int i = 0; i < nums1.size(); i++)
        {
            if (set1.find(nums1[i]) == set1.end())
            {
                set1.insert(nums1[i]);
            }
        }
        for (int i = 0; i < nums2.size(); i++)
        {
            if (set2.find(nums2[i]) == set2.end())
            {
                set2.insert(nums2[i]);
            }
        }

        return getInterSec(set1, set2);
    }
};

void test()
{
    Solution solution;
    vector<int> nums1{2, 2}, nums2{1, 2, 2, 1};
    vector<int> resu;
    resu = solution.intersection(nums1, nums2);
}

int main()
{
    test();
    return 0;
}