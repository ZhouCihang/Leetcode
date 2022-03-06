#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:

    vector<vector<int> > ans;
    vector<int> t;
    int result=0;
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <(1<<n); i++) {
            int res=0;
            t.clear();
            for (int j = 0; j < n; j++){
                if(i & (1 <<j)){
                    t.push_back(nums[j]);
                    res ^= nums[j];
                }
            }
            result += res;
            ans.push_back(t);
        }

        return result;
    }
};

int main(){
    Solution s;
    vector<int> nums{5,1,6};
    cout << s.subsetXORSum(nums) << endl;

    return 0;
}