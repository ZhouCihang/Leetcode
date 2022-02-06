#include <iostream>
using namespace std;
#include <vector>

void printVector(vector<int> &nums);

class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        // vector<int> result;
        // int sum = 0;
        // for (int i = 1; i <= nums.size(); i++)
        // {
        //     for (int j = 0; j < i; j++)
        //     {
        //         sum += nums[j];
        //     }
        //     result.push_back(sum);
        //     sum = 0;
        // }
        // return result;
        for(int i=1;i<nums.size();i++){
            nums[i] += nums[i-1];
            printVector(nums);
        }
		return nums;
    }
};

void printVector(vector<int> &nums){
    for (int i = 0; i< nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

void test()
{
    Solution sol;

    vector<int> nums{1, 2, 3, 4};
    vector<int> res = sol.runningSum(nums);

    for (int i = 0; i< res.size(); i++)
    {
        cout << res[i] << endl;
    }
}

int main()
{
    test();
    return 0;
}
