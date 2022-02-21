#include <iostream>
using namespace std;
#include <unordered_map>

class Solution
{
public:
    int romanToInt2(string S)
    {
        int ans = 0, num = 0;
        for (int i = S.size() - 1; ~i; i--)
        {
            switch (S[i])
            {
            case 'I':
                num = 1;
                break;
            case 'V':
                num = 5;
                break;
            case 'X':
                num = 10;
                break;
            case 'L':
                num = 50;
                break;
            case 'C':
                num = 100;
                break;
            case 'D':
                num = 500;
                break;
            case 'M':
                num = 1000;
                break;
            }
            if (4 * num < ans)
                ans -= num;
            else
                ans += num;
        }
        return ans;
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
    cout << s.romanToInt("MCMXCIIIIV") << endl;
    return 0;
}