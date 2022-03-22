#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<int> > result;
    vector<vector<int> > combine(int n, int k)
    {
        vector<int> path;
        backtracking(path, n, k, 1);
        return result;
    }
    void backtracking(vector<int> &path, int n, int k, int index)
    {
        if(path.size() >= k){
            result.push_back(path);
            return;
        }
        for(int i = index; i <= n; i++){
            path.push_back(i);
            backtracking(path, n, k, i + 1);
            path.pop_back();
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int> > result;
    result = s.combine(4, 2);
    for (int i = 0; i < result.size(); i++){
        for(int j = 0; j < result[i].size(); j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}