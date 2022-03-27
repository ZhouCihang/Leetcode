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

    vector<int> intersectionTwoPointer(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int length1 = nums1.size(), length2 = nums2.size();
        int index1 = 0, index2 = 0;
        vector<int> intersection;
        while (index1 < length1 && index2 < length2)
        {
            int num1 = nums1[index1], num2 = nums2[index2];
            if (num1 == num2)
            {
                // 保证加入元素的唯一性
                if (!intersection.size() || num1 != intersection.back())
                {
                    intersection.push_back(num1);
                }
                index1++;
                index2++;
            }
            else if (num1 < num2)
            {
                index1++;
            }
            else
            {
                index2++;
            }
        }
        return intersection;
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