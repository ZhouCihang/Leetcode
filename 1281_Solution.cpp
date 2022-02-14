#include <iostream>
using namespace std;
//#include <math.h>
#include <cmath>

class Solution {
public:
    int subtractProductAndSum(int n) {
        int prod = 1;
        int sum = 0;
        
        while(n > 0){
            int temp = n%10;
            
            n /= 10;
            
            prod = prod * temp;
            sum = sum + temp;
        }
        return prod - sum; 
    }

    int numberOfSteps (int num) {
        return num == 0 ? 0 : log2(num) + bitset<32>(num).count();
}
};

int main(){

    Solution s = Solution();
    cout << s.subtractProductAndSum(234)<<endl;

    cout <<s.numberOfSteps(14) << endl;


    return 0;
}