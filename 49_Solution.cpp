#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution
{
public:
    vector<vector<string> > groupAnagrams(vector<string> &strs)
    {
        vector<vector<string> > result;
        unordered_map<string, vector<string>> mp;
        for(string& str : strs){
            string key = str;
            sort(key.begin(), key.end());
            mp[key].push_back(str);
        }
        for(auto it = mp.begin(); it != mp.end();++it){
            result.push_back(it->second);
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<string> > result;
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    result = s.groupAnagrams(strs);
    return 0;
}