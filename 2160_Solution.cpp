#include <iostream>
using namespace std;
#include <vector>
#include <cmath>

void printVector(vector<int> &nums)
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
    int minimumSum(int num)
    {
        vector<int> digits;
        while (num != 0)
        {
            digits.push_back(num%10);
            num = num / 10;
        }

        sort(digits.begin(), digits.end());
        
        return (digits[0] + digits[1]) * 10 + digits[2] + digits[3];
    }
};

void test()
{
    Solution s;
    cout << s.minimumSum(2932);
}

int main()
{
    test();
    return 0;
}