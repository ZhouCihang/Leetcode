#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> userMap;
        
        for(int i = 0; i < logs.size(); i++){
            userMap[logs[i][0]].insert(logs[i][1]);
        }

        vector<int> result(k);
        for(auto &m : userMap){
            result[m.second.size() - 1]++;
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