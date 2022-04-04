#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <queue>

class Solution
{
public:
    vector<vector<int> > highFive(vector<vector<int> > items)
    {
        unordered_map<int, priority_queue<int>> mp;
        for(auto &item: items){
            mp[item[0]].push(item[1]);
        }
        vector<vector<int> > result;
        for(auto &it:mp){
            auto &q = it.second;
            if(q.size() == 0) continue;
            int sum = 0;
            for(int j = 0; j < 5; j++){
                sum += q.top();
                q.pop();
            }
            result.push_back({it.first, sum / 5});
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > items{{1, 91}, {1, 92}, {2, 93}, {2, 97}, {1, 60}, {2, 77}, {1, 65}, {1, 87}, {1, 100}, {2, 100}, {2, 76}};
    vector<vector<int> > result;
    result = s.highFive(items);
    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}