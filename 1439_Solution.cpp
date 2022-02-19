#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:

    void printVector(vector<int> &v){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }

    int kthSmallest(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        vector<int> res(mat[0]);
        printVector(res);

        for(int i = 1; i < rows; i++){
            vector<int> curr;
            for(int a:res){
                for(int b:mat[i]){
                    cout << "a: " << a << " b: " << b << endl;
                    curr.push_back(a+b);
                }
                cout << endl;
            }
            
            sort(curr.begin(), curr.end());
            printVector(curr);
            cout << "resting"<<endl;

            int offset = min(k, int(curr.size()));
            cout <<"offset : " << offset << endl;

            res.assign(curr.begin(), curr.begin()+offset);
            printVector(res);
        }

        return res.back();
    }
};

void test(){
    Solution solution;
    vector<vector<int>> mat{{1, 10, 10}, {1, 4, 5}, {2,3,6}};
    cout << solution.kthSmallest(mat, 7) << endl;
}

int main(){
    test();
    return 0;
}