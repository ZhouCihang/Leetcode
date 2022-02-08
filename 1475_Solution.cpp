#include <iostream>
using namespace std;
#include <vector>

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
    vector<int> finalPrices(vector<int> &prices)
    {
        vector<int> result;

        for (int i = 0; i < prices.size(); i++)
        {
            int j;
            for (j = i + 1; j < prices.size(); j++)
            {
                if (prices[j] <= prices[i])
                {
                    result.push_back(prices[i] - prices[j]);
                    break;
                }
            }
            if (j == prices.size())
                result.push_back(prices[i]);
        }
        return result;
    }
};

void test()
{
    Solution solution;
    vector<int> res;
    vector<int> prices{8, 4, 6, 2, 3};

    res = solution.finalPrices(prices);
    printVector(res);
}

int main()
{
    test();
    return 0;
}