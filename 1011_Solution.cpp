#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <numeric>

class Solution
{
public:
    int shipWithinDays(vector<int> &weights, int days)
    {
        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        //assume weight capacity is within 1000 range
        while (left < right)
        {
            int mid = (left + right) / 2;
            // need 为需要运送的天数
            // cur 为当前这一天已经运送的包裹重量之和
            int need = 1, cur = 0;

            for (auto &weight : weights)
            {
                if (cur + weight > mid)
                {
                    ++need;
                    cur = 0;
                }
                cur += weight;
            }
            if (need <= days)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main()
{
    Solution solution;
    vector<int> weights{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << solution.shipWithinDays(weights, 5) << endl;
    return 0;
}