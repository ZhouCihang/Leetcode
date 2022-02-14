#include <iostream>
using namespace std;

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
        cout<<prod<<" "<<sum<<endl;

        return prod - sum;
        
        
    }
};

int main(){

    Solution s = Solution();
    cout << s.subtractProductAndSum(234)<<endl;

    return 0;
}