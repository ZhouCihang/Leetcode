#include <iostream>
using namespace std;
#include <vector>
#include <stack>

void printVector(vector<string> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> result;

        int index = 0;
        for (int i = 1; i <= n; i++)
        {

            result.push_back("Push");
            if (target[index] != i)
            {
                result.push_back("pop");
            }
            else
            {
                index++;
                if (index >= target.size())
                {
                    return result;
                }
            }
        }
        return result;
    }
};

void test()
{
    Solution solution;
    vector<string> result;
    vector<int> target{1, 3};
    result = solution.buildArray(target, 3);
    printVector(result);
}

int main()
{
    test();
    return 0;
}