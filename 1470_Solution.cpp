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
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> result;
        for(int i = 0; i < n; i++){
            result.push_back(nums[i]);
            result.push_back(nums[i+n]);
        }
        return result;
    }
};

void test(){
    Solution solution;
    vector<int> result;
    vector<int> nums {2,5,1,3,4,7};

    result = solution.shuffle(nums, 3);
    printVector(result);
}

int main(){
    test();
    return 0;
}