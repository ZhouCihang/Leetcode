#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    void subsetsUtil(vector<int> &A, vector<vector<int> > &res,
                     vector<int> &subset, int index)
    {
        res.push_back(subset);
        for (int i = index; i < A.size(); i++)
        {

            // include the A[i] in subset.
            subset.push_back(A[i]);

            // move onto the next element.
            subsetsUtil(A, res, subset, i + 1);

            // exclude the A[i] from subset and triggers
            // backtracking.
            subset.pop_back();
        }

        return;
    }

    vector<vector<int> > subsets2(vector<int> &A)
    {
        vector<int> subset;
        vector<vector<int> > res;

        // keeps track of current element in vector A;
        int index = 0;
        subsetsUtil(A, res, subset, index);

        return res;
    }

    vector<int> t;
    vector<vector<int> > ans;
    vector<vector<int> > subsets(vector<int> &nums)
    {
        int n = nums.size();
        for(int mask = 0; mask<(1<<n); ++mask){
            t.clear();
            for(int i = 0; i<n; ++i){
                if(mask & (1<<i)){
                    t.push_back(nums[i]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};

void test()
{
    Solution s;
    vector<vector<int> > result;
    vector<int> nums{1, 2, 3};
    result = s.subsets(nums);
}

int main()
{
    test();
    return 0;
}