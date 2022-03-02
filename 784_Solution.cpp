#include <iostream>
using namespace std;
#include <vector>
#include <ctype.h>

class Solution {
public:
    vector<string> result;
    vector<string> letterCasePermutation(string s) {
        dfs(s, 0);
        return result;
    }
    
    void dfs(string s, int k){
        if(k == s.length()){
            result.emplace_back(s);
            return;
        }
        
        if(isdigit(s[k])){
            dfs(s, k+1);
        }
        else{
            s[k]=tolower(s[k]);
            dfs(s, k+1);
            s[k]=toupper(s[k]);
            dfs(s, k+1);
        }
    }
};

int main(){
    Solution s;
    vector<string> res;
    res = s.letterCasePermutation("a1b2");
    return 0;
}