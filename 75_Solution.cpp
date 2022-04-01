#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i=0; i<nums.size()-1; ++i){
            for(int j = i+1; j < nums.size(); ++j){
                if(nums[i] > nums[j])
                    swap(nums[i], nums[j]);
            }
        }

        for(int i=0; i<nums.size(); ++i){
            cout << nums[i] << " ";
        }
        cout << endl;
    }
};

int main(){
    Solution s;
    vector<int> nums{2,0,2,1,1,0};
    s.sortColors(nums);
    return 0;
}