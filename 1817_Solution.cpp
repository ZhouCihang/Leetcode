#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <set>

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, set<int>> userMap;
        unordered_map<int, set<int>>::iterator it;
        
        for(int i = 0; i < logs.size(); i++){
            int id = logs[i][0];
            int sec = logs[i][1];
            userMap[id].insert(sec);
        }

        vector<int> result(k,0);
        for (auto it = userMap.begin(); it != userMap.end(); ++it) {
            result[it->second.size()-1]++;
        }
        return result;
    }
};

void test(){
    vector<vector<int> > logs{{0,5}, {1,2}, {0,2}, {0,5},{1,3}};
    vector<int> result;
    Solution solution;
    result = solution.findingUsersActiveMinutes(logs, 5);

    for(int i = 0; i< result.size(); i++){
        cout<< result[i]<< " ";
    }
    cout << endl;
}

int main(){
    test();
    return 0;
}