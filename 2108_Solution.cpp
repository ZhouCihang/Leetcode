#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    bool isPalindrome(string str){
        int left = 0, right = str.length() - 1;
        while(left <= right) {
            if(str[left] != str[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        string str = "";
        for(int i = 0; i < words.size(); i++){
            if(isPalindrome(words[i])){
                return words[i];
            }
        }
        return str;
    }
};

void test(){
    Solution s;
    vector<string> words{"abc","car","adaa","radcecar","cool"};
    cout << s.firstPalindrome(words) << endl;
}

int main(){
    test();
    return 0;
}