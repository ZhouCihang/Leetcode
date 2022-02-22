#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        for (int i = 0, next = 0; i < nums.size(); ++i)
        {
            if (nums[i])
            {   cout << i <<" i: " << next <<" next: "<<endl;
                swap(nums[i], nums[next++]);
            }

            for (int i = 0; i < nums.size(); i++)
            {
                cout << nums[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums{0,1,0,1,2,3};
    s.moveZeroes(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}