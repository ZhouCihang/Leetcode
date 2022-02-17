#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int minOperations(int n) {
        int end = 2 * (n-1) + 1;
        int mid = (end + 1)/2;

        int result = 0;
        for(int i = mid - 1; i >= 1; i-=2){
            result += i;
        }
        
        return result;
    }
};

void test(){
    Solution solution;
    cout << solution.minOperations(6) << endl;
}

int main(){
    test();
    return 0;
}
