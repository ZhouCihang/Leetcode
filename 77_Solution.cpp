#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int> > result;
    vector<int> temp;
    vector<vector<int>> combine(int n, int k) {
        getCombine(n, k, 1, temp);
        return result;
    }

    void getCombine(int n, int k, int start, vector<int> temp){
        if(k == 0) {
            result.push_back(temp);
            return;
        }
        for(int i = start; i <= n-k+1; i++) {
            temp.push_back(i);
            getCombine(n, k-1, i+1, temp);
            temp.pop_back();
        }
    }
};

int main() {
    Solution s;
    vector<vector<int>> result;
    result = s.combine(4,2);
    for(int i = 0; i <result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}