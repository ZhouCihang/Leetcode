#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool checkSubarraySum(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_set<int> rSet;
        vector<int> sum(n+1,0);
        cout<<sum[0]<<endl;
        for(int i = 1; i <= n; ++i){
            sum[i] = sum[i-1] + nums[i - 1];
            cout<<sum[i]<<" ";
        }
        cout << endl;

        for(int i = 2; i <= n; ++i){
            rSet.insert(sum[i-2]%k);
            if(rSet.find(sum[i]%k) != rSet.end()) return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> nums{23, 2, 6, 4, 7};
    cout << s.checkSubarraySum(nums, 7) << endl;
    return 0;
}