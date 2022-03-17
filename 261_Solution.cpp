#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>

class Solution
{
public:
    bool validTree(int n, vector<pair<int, int> > &edges)
    {
        vector<unordered_set<int> > g(n, unordered_set<int>());
        unordered_set<int> s{{0}};
        queue<int> q{{0}};

        for (auto &a : edges)
        {
            g[a.first].insert(a.second);
            g[a.second].insert(a.first);
        }
        while (!q.empty())
        {
            int t = q.front();
            q.pop();
            for(auto &a : g[t]){
                if(s.count(a)) return false;
                s.insert(a);
                q.push(a);
                g[a].erase(t);
            }
        }
        return s.size() == n;
    }
};

int main()
{
    Solution s;
    vector<pair<int, int> > edges{{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    cout << s.validTree(5, edges) << endl;
    return 0;
}