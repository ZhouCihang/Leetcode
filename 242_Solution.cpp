#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;

        unordered_map<char, int> mp;
        for (auto &c : s)
            mp[c]++;

        for (auto &j : t)
        {
            mp[j]--;
            if (mp[j] < 0)
                return false;
        }
        return true;
    }
    bool isAnagram2(string s, string t)
    {
        if (s == t)
            return true;
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> umap;
        for (int i = 0; i < s.size(); i++)
        {
            umap[s[i]]++;
            umap[t[i]]--;
        }
        for (auto it : umap)
        {
            if (it.second)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    cout << s.isAnagram("ab", "a");
    return 0;
}