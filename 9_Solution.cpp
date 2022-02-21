#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
        string str  = to_string(x);
        int left = 0, right = str.length() - 1;

        while (left <= right) {
            if(str[left] != str[right]){
                return false;
            }else{
                left = left + 1;
                right = right - 1;
            }
        }

        return true;
    }
};

int main(){
    Solution s;
    cout << s.isPalindrome(12343821) << endl;
    return 0;
}