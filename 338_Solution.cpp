#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int countOnes(int x){
        int ones = 0;
        while(x>0){
            cout << " x: " << x <<" x-1: " <<x-1<<endl;
            x &= (x-1);
            ones++;
        }
        return ones;
    }

    vector<int> countBits(int n) {
        vector<int> bits(n+1);
        for (int i = 0; i <= n; i++){
            bits[i] = countOnes(i);
        }
        return bits;
    }
};

void test(){
    Solution s;
    vector<int> result;
    result = s.countBits(8);
    // 0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4
}

int main(){
    test();
    return 0;
}