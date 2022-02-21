#include <iostream>
using namespace std;
#include <vector>
#include <deque>

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        deque<int> dq;
        for (int i = 0; i < nums.size(); i++)
        {
            dq.push_back(nums[i]);
        }

        for (int j = 0; j < k; j++)
        {
            int temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
        }

        int idx = 0;
        for (auto it = dq.begin(); it != dq.end(); ++it)
        {
            nums[idx] = *it;
            idx++;
        }
    }
};

void test()
{
    Solution solution;
    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    solution.rotate(nums, 3);
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

int main()
{
    test();
    return 0;
}