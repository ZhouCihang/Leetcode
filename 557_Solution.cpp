#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        for (int j = 0; j < s.length(); j++) {
            if(s[j] == ' ') {
                cout << i <<" " << j << endl;
                reverse(s.begin()+i, s.begin()+j);
                i = j+1;
            }
        }
        reverse(s.begin()+i, s.end());
        return s;
    }
};

void test(){
    Solution s;
    cout<<s.reverseWords("Let's take LeetCode contest")<< endl;
}

int main(){
    test();
    return 0;
}