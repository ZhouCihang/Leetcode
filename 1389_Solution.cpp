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
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> result;
        for(int i = 0; i < index.size(); i++){
            result.insert(result.begin()+index[i], nums[i]);
        }
        return result;
    }
};

void test(){
    Solution s;
    vector<int> nums{0,1,2,3,4};
    vector<int> index{0,1,2,2,1};
    vector<int> result;

    result = s.createTargetArray(nums, index);
    printVector(result);
}

int main(){
    test();
    return 0;
}