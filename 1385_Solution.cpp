#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int cnt = 0;
        for (auto &x: arr1) {
            unsigned p = lower_bound(arr2.begin(), arr2.end(), x) - arr2.begin();
            bool ok = true;
            if (p < arr2.size()) {
                ok &= (arr2[p] - x > d);
            }
            if (p - 1 >= 0 && p - 1 <= arr2.size()) {
                ok &= (x - arr2[p - 1] > d);
            }
            cnt += ok;
        }
        return cnt;
    }
};

int main()
{
    Solution solution;
    vector<int> arr1{4, 5, 8}, arr2{10, 9, 1, 8};
    cout<<solution.findTheDistanceValue(arr1, arr2, 2)<<endl;
    return 0;
}