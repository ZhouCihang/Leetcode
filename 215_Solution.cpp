#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        // sort(nums.begin(), nums.end());
        // return nums[nums.size()-k];

        /*Srand是种下随机种子数，你每回种下的种子不一样，
        用Rand得到的随机数就不一样。为了每回种下一个不一样的种子，
        所以就选用Time(0)，Time(0)是得到当前时时间值（因为每时每刻时间是不一样的了）。*/
        srand(time(0));
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }
    int quickSelect(vector<int>& a, int l, int r, int index) {
        int q = randomPartition(a, l, r);
        if (q == index) {
            return a[q];
        } else {
            return q < index ? quickSelect(a, q + 1, r, index) : quickSelect(a, l, q - 1, index);
        }
    }

    inline int randomPartition(vector<int>& a, int l, int r) {
        int i = rand() % (r - l + 1) + l;
        swap(a[i], a[r]);
        return partition(a, l, r);
    }

    //quick sort
    inline int partition(vector<int>& a, int l, int r) {
        int x = a[r], i = l - 1;
        for (int j = l; j < r; ++j) {
            if (a[j] <= x) {
                swap(a[++i], a[j]);
            }
        }
        swap(a[i + 1], a[r]);
        return i + 1;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{3, 2, 1, 5, 6, 4};
    cout << solution.findKthLargest(nums, 2) << endl;
    return 0;
}