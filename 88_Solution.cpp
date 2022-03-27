#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void mergeWithExtraSpace(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int pt1 = 0, pt2 = 0;
        int sorted[m + n];
        int cur;

        while (pt1 < m || pt2 < n)
        {
            if (pt1 == m)
            {
                cur = nums2[pt2++];
            }
            else if (pt2 == n)
            {
                cur = nums1[pt1++];
            }
            else if (nums1[pt1] < nums2[pt2])
            {
                cur = nums1[pt1++];
            }
            else
            {
                cur = nums2[pt2++];
            }
            sorted[pt1 + pt2 - 1] = cur;
        }
        for (int i = 0; i < m + n; i++)
        {
            nums1[i] = sorted[i];
        }
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int pt1 = m - 1, pt2 = n - 1;
        int tail = m + n - 1;
        int cur;

        while (pt1 >= 0 || pt2 >= 0)
        {
            if (pt1 == -1)
            {
                cur = nums2[pt2--];
            }
            else if (pt2 == -1)
            {
                cur = nums1[pt1--];
            }
            else if (nums1[pt1] > nums2[pt2])
            {
                cur = nums1[pt1--];
            }
            else
            {
                cur = nums2[pt2--];
            }
            nums1[tail--] = cur;
        }
    }
};

int main()
{
    Solution solution;
    vector<int> nums1{1, 2, 3};
    vector<int> nums2{2, 5, 6};
    solution.merge(nums1, 3, nums2, 3);
    return 0;
}