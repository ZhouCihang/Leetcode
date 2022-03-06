#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<string> result;
    vector<string> permutation(string s) {
        string path = "";
        vector<bool> used{false};
        backtracking(s, path, used);
        return result;
    }
    void backtracking(string s, string path, vector<bool> &used){
        if(path.length() == s.length()){
            result.push_back(path);
            return;
        }

        for(int i = 0; i < s.length(); i++){
            if(s[i] == s[i-1] && i > 0 && used[i-1] == false){
                continue;
            }
            if(used[i] == false){
                used[i] = true;
                path.push_back(s[i]);
                backtracking(s, path, used);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};

int main(){
    vector<string> perm;
    Solution solution;
    perm = solution.permutation("abc");

    for(int i = 0; i < perm.size(); i++){
        cout << perm[i] << " ";
    }
    cout << endl;
    return 0;
}