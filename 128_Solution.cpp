#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <string>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int result = 0, curLength = 1;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); ++i){
            if(nums[i] == nums[i-1] + 1){
                curLength++;
            }else if(nums[i] == nums[i - 1]){
                continue;
            }else{
                result = max(result, curLength);
                curLength = 1;
            }
        }
        return max(result, curLength);
    }
};

int main(){
    Solution solution;
    vector<int> nums{9,1,4,7,3,-1,0,5,8,-1,6};
    cout << solution.longestConsecutive(nums) << endl;
    return 0;
}