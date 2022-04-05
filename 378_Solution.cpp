#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution
{
public:
    int kthSmallest(vector<vector<int> > &matrix, int k)
    {
        priority_queue<int, vector<int>, less<int>> q;
        //priority_queue<int> q;
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = 0; j < matrix[i].size(); ++j){
                q.emplace(matrix[i][j]);
                if(q.size()>k){
                    q.pop();
                }
            }
        }
        //return q.top();

        while(!q.empty()){
            cout<< q.top()<<endl;
            q.pop();
        }
        return 0;
    }
};

int main()
{
    Solution solution;
    vector<vector<int> > matrix{{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout << solution.kthSmallest(matrix, 8) << endl;
    return 0;
}