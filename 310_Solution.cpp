#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int> > &edges)
    {
        vector<int> res;
        if (n == 1)
            return {0};
        vector<int> degree(n, 0);
        vector<vector<int> > G(n);
        queue<int> q;

        for (auto &edge : edges)
        {
            int from = edge[0];
            int to = edge[1];
            G[from].push_back(to);
            G[to].push_back(from);
            degree[to]++;
            degree[from]++;
        }

        for(int i = 0; i < G.size(); i++){
            for(int j = 0; j < G[i].size(); j++){
                cout << G[i][j] << " ";
            }
            cout << endl;
        }
        cout <<"G tesing"<<endl;

        for(int i = 0; i < degree.size(); i++){
            cout << degree[i] << " ";
        }
        cout << "degree tesing"<<endl;

        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 1)
                q.push(i);
        }
        int count = 0;

        while (!q.empty())
        {
            int size = q.size();
            res.clear();
            for (int i = 0; i < size; i++){
                int cur = q.front();
                cout<<cur<<" ";
                q.pop();
                res.push_back(cur);
                degree[cur]--;
                for(auto &m:G[cur]){
                    degree[m]--;
                    if(degree[m] == 1)
                        q.push(m);
                }
            }
            cout <<endl;
        }
        return res;
    }

};

int main()
{
    Solution s;
    vector<int> result;
    vector<vector<int> > edges{{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    result = s.findMinHeightTrees(6, edges);

    for(int i = 0; i<result.size(); i++){
        cout<< result[i] << " ";
    }
    cout << endl;
    return 0;
}