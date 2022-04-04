#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <queue>

// struct cmp
// {
//     bool operator()(pair<string, int> &a, pair<string, int> &b)
//     {
//         return a.second == b.second ? a.first < b.first : a.second > b.second;
//     }
// };

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> mp;
        for (auto &word : words)
        {
            mp[word]++;
        }
        //priority_queue<pair<string, int>, vector<pair<string, int> >, cmp> q;

        auto cmp = [](const pair<string, int> &a, const pair<string, int> &b)
        {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };
        priority_queue<pair<string, int>, vector<pair<string, int> >, decltype(cmp)> q(cmp);

        for (auto& it : mp) {
            q.emplace(it);
            if (q.size() > k) {
                q.pop();
            }
        }
        vector<string> ret(k);
        for (int i = k - 1; i >= 0; i--) {
            ret[i] = q.top().first;
            q.pop();
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<string> words{"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> result;
    result = s.topKFrequent(words, 2);
    return 0;
}