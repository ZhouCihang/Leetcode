#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i = 0; i<=31; i++) {
            result = (result << 1)|(n & 1);
            n>>=1;
        }
        return result;
    }
};

int main(){
    Solution sl;

    cout <<sl.reverseBits(0b00000000000000000000001001110100)<< endl;
    return 0;
}