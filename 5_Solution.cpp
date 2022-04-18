#include <iostream>
using namespace std;
#include <string>

class Solution
{
public:
    string longestPalindrome(string s)
    {
        if(s.length() < 2) return s;
        int maxLen = 1;
        string result = s.substr(0,1);
        for(int i = 0; i < s.length()-1; ++i){
            string oddstr = centerExpand(s, i, i);
            cout<<oddstr<<endl;
            string evenstr = centerExpand(s, i, i+1);
            cout<<evenstr<<endl;
            cout<<endl;
            string longstr = oddstr.length() > evenstr.length() ? oddstr : evenstr;
            if(longstr.length() > maxLen){
                maxLen = longstr.length();
                result = longstr;
            }
        }
        return result;
    }

    string centerExpand(string s, int left, int right){
        while(left >= 0 && right < s.length()){
            if(s[left] != s[right]) break;
            left--;
            right++;
        }
        return s.substr(left+1, right-left - 1);
    }

    bool checkPalindrome(string s){
        int left = 0, right = s.length() - 1;
        while(left < right){
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.longestPalindrome("babad") << endl;
    return 0;
}