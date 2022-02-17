#include <iostream>
using namespace std;
#include <vector>

void printVector(vector<bool> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

class Solution
{
public:
    bool arithCheck(vector<int> &v)
    {
        int i = 0;
        int temp = v[i + 1] - v[i];

        while (i < v.size() - 1)
        {
            if (v[i + 1] - v[i] != temp)
            {
                return false;
            }
            i++;
        }
        return true;
    }

    vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
    {
        int n = l.size();
        vector<bool> result;
        vector<int> temp;

        for (int i = 0; i < n; i++)
        {
            for (int j = l[i]; j <= r[i]; j++)
            {
                temp.push_back(nums[j]);
            }

            sort(temp.begin(), temp.end());
            result.push_back(arithCheck(temp));
            temp.clear();
        }
        return result;
    }
};

void test()
{
    Solution solution;
    vector<int> nums{4, 6, 5, 9, 3, 7};
    vector<int> l{0, 0, 2};
    vector<int> r{2, 3, 5};
    vector<bool> result;

    result = solution.checkArithmeticSubarrays(nums, l, r);
}

int main()
{
    test();
    return 0;
}