#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int y = 0;
        
        while( x != 0){
            if (y > 214748364 || y < -214748364) return 0;
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }
};

int main(){
    Solution s;
    cout << s.reverse(-3221) << endl;
    return 0;
}