#include <iostream>
using namespace std;
#include <string>

class Solution
{
public:
    bool isPalindrome(string s)
    {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        cout << sgood << endl;

        int r = sgood.length() - 1;
        int l = 0;
        while (l <= r)
        {
            if (tolower(sgood[l]) != tolower(sgood[r]))
                return false;
            else
            {
                l++;
                r--;
            }
        }
        return true;
    }
};

int main()
{
    Solution s;
    //cout << s.isPalindrome("A man, a plan, a canal: Panama");
    cout << s.isPalindrome("race a car");
    return 0;
}