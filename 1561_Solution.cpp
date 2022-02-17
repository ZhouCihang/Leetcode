#include <iostream>
using namespace std;
#include <vector>

void printVector(vector<int>& v){
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end(), greater<int>());

        int num = piles.size()/3;
        int result = 0;
        for(int i = 0; i < num; i++){
            result += piles[1 + i*2];
        }
        return result;
    }
};

void test(){
    Solution solution;
    vector<int> piles{9,8,7,6,5,1,2,3,4};
    cout << solution.maxCoins(piles) << endl;
}

int main(){
    test();
    return 0;
}