#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    int romanToInt2(string S)
    {
        int res = 0;
        unordered_map<char, int> mp = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        for (int i = 0; i < S.length(); i++)
        {
            if (mp[S[i]] < mp[S[i + 1]] && i != S.length() - 1)
            {
                res = res - mp[S[i]];
                cout << S[i] << " Char: " << mp[S[i]] << " value:" << endl;
            }
            else
            {
                res += mp[S[i]];
                cout << S[i] << " Char: " << mp[S[i]] << " value:" << endl;
            }
        }
        return res;
    }

    int romanToInt(string s)
    {
        unordered_map<char, int> mp = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int res = mp[s.back()];
        for (int i = 0; i < s.size() - 1; i++)
        {
            if (mp[s[i]] < mp[s[i + 1]])
                res -= mp[s[i]];
            else
                res += mp[s[i]];
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt2("MCMXCIIIIV") << endl;
    return 0;
}