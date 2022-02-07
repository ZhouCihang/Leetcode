#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

void printVector(vector<bool> &nums){
    for (int i = 0; i< nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result;

        int maxI = *max_element(candies.begin(), candies.end());
        for(int i = 0; i< candies.size(); i++){
            if(candies[i]+extraCandies > maxI){
                result.push_back(true);
            }else{
                result.push_back(false);
            }
        }
        return result;
    }
};

void test(){
    Solution solution;
    vector<int> candies {2,3,5,1,3};
    vector<bool> result;

    result = solution.kidsWithCandies(candies, 3);
    printVector(result);
}

int main(){
    test();
    return 0;
}