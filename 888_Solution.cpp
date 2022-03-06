#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <numeric>

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {

        int sumAlice = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int sumBob = accumulate(bobSizes.begin(), bobSizes.end(), 0);

        int delta = (sumAlice - sumBob) / 2;
        unordered_set<int> mapAlice(aliceSizes.begin(), aliceSizes.end());
        vector<int> result;
        for(int i = 0; i < bobSizes.size(); i++){
            int val = bobSizes[i]+delta;
            if(mapAlice.find(val) != mapAlice.end()){
                result = vector<int>{val, bobSizes[i]};
                break;
            }
        }

        return result;
    }
};

void test(){
    Solution solution;
    vector<int> aliceSizes{2}, bobSizes{1,3};
    vector<int> result;
    result = solution.fairCandySwap(aliceSizes, bobSizes);

    for (int i = 0; i < result.size(); i++){
        cout<< result[i] << " ";
    }
    cout << endl;
}

int main(){
    test();
    return 0;
}