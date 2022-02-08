#include <iostream>
using namespace std;
#include <vector>
#include <stack>

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
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<int> s;
        vector<int> result(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++)
        {
            while (!s.empty() && temperatures[i] > temperatures[s.top()])
            {
                int previousIndex = s.top();
                result[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return result;
    }
};

void test()
{
    Solution s;
    vector<int> temp;
    vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};

    temp = s.dailyTemperatures(temperatures);
    printVector(temp);
}

int main()
{
    test();
    return 0;
}
