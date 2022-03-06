#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int findKthPositiveMethod2(vector<int> &arr, int k)
    {
        vector<int> res(1000, 0);
        for (auto &i : arr)
        {
            res[i] = 1;
        }

        int count = 0, result = -1;
        for (int i = 1; i <= res.size(); i++)
        {
            if (res[i] == 0)
            {
                count++;
            }
            if (count == k)
            {
                result = i;
                break;
            }
        }
        return result;
    }
    int findKthPositive(vector<int> &arr, int k)
    {
        if (k < arr[0])
            return k;
        
        int low(0), high(arr.size());
        while (low < high)
        {
            int mid = low + ((high - low) >> 1);
            if (arr[mid] - mid - 1 < k)
                low = mid + 1;
            else
                high = mid;
        }
        return low + k;
    }
};

void test()
{
    Solution solution;
    vector<int> arr{1, 2, 3, 4};
    cout << solution.findKthPositive(arr, 2) << endl;
}

int main()
{
    test();
    return 0;
}