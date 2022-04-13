#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <queue>

bool TopSort(vector<vector<int> > &G, int n, vector<int> &inDegree)
{
    int num = 0;
    queue<int> q;

    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }

    while(!q.empty()){
        int u = q.front();
        q.pop();
        cout << u << " "<<endl;
        for(int i = 0; i < G[u].size(); i++){
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v]== 0)
                q.push(v);
        }
        G[u].clear();
        num++;
    }
    if(num == n) return true;
    else return false;
}

int main()
{
    int n, m;
    cout << "Enter Node and Edge number: ";
    cin >> n >> m;
    vector<vector<int> > G(n);

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cout << "please enter edge number: " << i + 1 << " node: ";
        cin >> x >> y;
        G[x].push_back(y);
    }

    cout << "Topology Sortings:" << endl;
    vector<int> inDegree(n);

    for (auto &x : G)
    {
        for (auto &y : x)
        {
            inDegree[y]++;
        }
    }

    cout << TopSort(G, n, inDegree);
    return 0;
}