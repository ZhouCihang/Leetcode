#include <iostream>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == t){
            return true;
        }
        int n = s.length();
        int m = t.length();

        int i = 0, j = 0;
        while(j < m) {
            if(s[i] == t[j]){
                i++;
            }
            j++;

            if(i >= n){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution s;
    cout << s.isSubsequence("axc", "ahbgdc")<< endl;
    return 0;
}