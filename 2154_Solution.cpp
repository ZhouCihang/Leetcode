#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        bool m[1001] = {};
        for (int n: nums){
            m[n] = true;
        }

        while(original <= 1000 && m[original]){
            original *= 2;
        }
        return original;

    }
};

void test(){
    Solution s;
    vector<int> nums{5, 3, 6, 1, 12};

    cout << s.findFinalValue(nums,3);
}

int main(){
    test();
    return 0;
}