#include <iostream>
using namespace std;
#include <vector>

void printVector(vector<int> &nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> result;

        for(int i = 0; i < nums.size(); i++){
            if(target == nums[i]){
                result.push_back(i);
            }
        }
        return result;
    }
};

void test(){
    Solution solution;
    vector<int> nums{1, 2, 5, 2, 3};
    vector<int> result;

    result = solution.targetIndices(nums, 2);
    printVector(result);
}

int main(){
    test();
    return 0;
}