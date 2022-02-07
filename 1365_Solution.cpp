#include <iostream>
using namespace std;
#include <vector>

void printVector(vector<int> &nums){
    for (int i = 0; i< nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){
            int count = 0;
            for(int j = 0; j < nums.size(); j++){
                if(nums[i] > nums[j] && i!=j){
                    count++;
                } 
            }
            result.push_back(count);
        }
        return result;
    }
};

void test(){
    Solution sol;
    vector<int> nums{8,1,2,2,3};
    vector<int> result;
    result = sol.smallerNumbersThanCurrent(nums);
    printVector(result);
}

int main(){
    test();
    return 0;
}