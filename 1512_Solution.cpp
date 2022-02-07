#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result =0;
        for (int i = 0; i< nums.size(); i++){
            for (int j = i; j< nums.size(); j++){
                if(nums[j] == nums[i] && i < j){
                    //cout <<"i: " << i << " j: " << j << endl;
                    result +=1;
                }
            }
        }
        return result;
    }
};

void test(){
    Solution s;
    vector<int> nums {1,2,3,1,1,3};
    cout << s.numIdenticalPairs(nums) << endl;
}

int main(){
    test();
    return 0;
}