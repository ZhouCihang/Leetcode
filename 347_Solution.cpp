#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <queue>

struct cmp{
    bool operator()(pair<int, int> &a, pair<int, int> &b){
        return a.second > b.second;
    }
};

class Solution
{
public:
    // bool cmp(pair<int, int> &a, pair<int, int> &b)
    // {
    //     return a.second > b.second;
    // }
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (auto &num : nums)
        {
            mp[num]++;
        }

        //priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        for (auto &[num, count] : mp)
        {
            if (q.size() == k)
            {
                if (q.top().second < count)
                    {
                        q.pop();
                        q.emplace(num, count);
                    }
            }
            else
            {
                q.emplace(num, count);
            }
        }
        vector<int> res;
        while(!q.empty()){
            res.push_back(q.top().first);
            q.pop();
        }
        return res;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{1, 1, 1, 2, 2, 3};
    vector<int> result;
    result = solution.topKFrequent(nums, 2);
    return 0;
}