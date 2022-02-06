#include <iostream>
using namespace std;

class Solution {
public:
    int balancedStringSplit(string s) {
        int num = 0;
        int result = 0;
        for (char c : s){
            if(c == 'L'){
                num--;
            }
            if(c == 'R'){
                num++;
            }

            if(num == 0){
                result++;
            }
        }

        return result;
    }
};

void test(){
    Solution s;
    cout<< s.balancedStringSplit("RLRRLLLLLRRRLRLR")<<endl;
}

int main(){
    test();
    return 0;
}