#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        // int bits = __builtin_popcount(n);
        // return bits;

        int res = 0;
        while(n > 0) {
            res++;
            n = n & (n-1);
        }
        return res;
    }
};  

int main(){
    Solution solution;
    cout << solution.hammingWeight(00000000000000000000000000001011) << endl;
    return 0;
}