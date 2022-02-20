#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long long left = 0, right = x;
        long long ans, mid;
        
        while(left <= right){
            mid = left + (right - left) / 2;

            if(mid * mid == x){
                return mid;
            }else if(mid * mid >x){
                right = mid - 1;
            }else{
                left = mid + 1;
                ans = mid;
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.mySqrt(8) <<endl;
    return 0;
}