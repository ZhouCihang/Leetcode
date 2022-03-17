#include <iostream>
using namespace std;
#include <vector>
#include <unordered_set>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(numCourses);
        cout<<"tesing"<<endl;
        for(int i = 0; i < prerequisites.size(); i++){
            G[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        for(int i = 0; i < G.size(); i++){
            for(int j = 0; j < G[i].size(); j++){
                cout << G[i][j] << " ";
            }
            cout << endl;
        }
        
        vector<int> inDegree(numCourses);
        for(auto &x:G){
            for(auto &y:x){
                inDegree[y]++;
            }
        }
        
        int num = 0;
        queue<int> q;
        
        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int i = 0; i < G[u].size(); i++){
                int v = G[u][i];
                inDegree[v]--;
                if(inDegree[v] == 0)
                    q.push(v);
            }
            G[u].clear();
            num++;
        }
        if(num == numCourses) return true;
        else return false;
    }
};

int main(){

    Solution s;
    vector<vector<int> > prerequisites{{2, 0},{2,1},{3,2},{4,2},{5,3},{6,4},{5,6},{7,5},{7,6}};
    cout<<s.canFinish(8, prerequisites)<< endl;
    return 0;

}