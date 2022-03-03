#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3){
            return 0;
        }
        int ans = 0, curr = 0, diff = nums[1] - nums[0];
        for(int i = 1; i < nums.size() - 1; i++){
            int cDiff = nums[i+1] - nums[i];
            if(cDiff == diff){
                curr++;
            }
            else{
                diff = cDiff;
                curr = 0;
            }
            cout<<" curr = "<<curr<<" ans = "<<ans<<endl;
            ans += curr;
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums{1,2,3,4, 5};
    cout << s.numberOfArithmeticSlices(nums) << endl;
    return 0;
}