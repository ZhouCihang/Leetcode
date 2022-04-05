#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
public:
    vector<vector<int> > kClosest(vector<vector<int> > &points, int k)
    {
        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b)
        {
            return a.first * a.first + a.second * a.second < b.first * b.first + b.second * b.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> q(cmp);

        for (int i = 0; i < points.size(); ++i)
        {
            q.emplace(points[i][0], points[i][1]);
            if (q.size() > k)
            {
                q.pop();
            }
        }

        vector<vector<int> > ret(k);
        for (int i = 0; i < k; ++i)
        {
            ret[i] = {q.top().first, q.top().second};
            q.pop();
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<vector<int> > points{{3, 3}, {5, -1}, {-2, 4}};
    vector<vector<int> > result;
    result = s.kClosest(points, 2);

    for(int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}