#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        auto get = [&](int i) -> pair<int, int> {
            if(i == -1 || i == n){
                return {0, 0};
            }
            return {1, nums[i]};
        };

        int left = 0, right = n - 1, ans = -1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (get(mid - 1) < get(mid) && get(mid) > get(mid + 1)) {
                ans = mid;
                break;
            }
            if (get(mid) < get(mid + 1)) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return ans;
    }
};

void test()
{
    Solution solution;
    vector<int> arr{0, 5,7,10, 5, 0};
    cout << solution.findPeakElement(arr) << endl;
}

int main()
{
    test();
    return 0;
}