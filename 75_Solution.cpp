#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] > nums[j])
                    swap(nums[i], nums[j]);
            }
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
    void sortColorsPartition(vector<int> &nums)
    {
        if(nums.size() < 2) return;
        int p0 = 0, i = 0, p2 = nums.size() - 1;
        while(i <= p2){
            if(nums[i] == 0){
                swap(nums[i], nums[p0]);
                i++;
                p0++;
            }else if(nums[i] == 1){
                i++;
            }else{
                swap(nums[i], nums[p2]);
                p2--;
            }
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Solution s;
    vector<int> nums{2, 0, 2, 1, 1, 0};
    s.sortColors(nums);
    return 0;
}