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
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;

        for (int i = 0; i < nums.size(); i+=2){
            result.insert(result.end(), nums[i], nums[i+1]);
        }

        return result;
    }
};

void test(){
    Solution s;
    vector<int> nums{1,2,3,4};
    vector<int> result;
    result = s.decompressRLElist(nums);
    printVector(result);
}

int main(){
    test();
    return 0;
}