#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res = 0;
        for(int i = 0; i < sentences.size();i++){
            int n = 0;
            for(int j = 0; j < sentences[i].length();j++){
                if(sentences[i][j] == ' '){
                    n++;
                }
            }
            res = max(res, n+1);
        }
        return res;
    }
};

void test() {
    vector<string> sentences;
    sentences.push_back("alice and bob love leetcode");
    sentences.push_back("i think so too");
    sentences.push_back("this is great thanks very much");

    Solution sol;
    int res = sol.mostWordsFound(sentences);
    cout << res << endl;
    
}

int main(){
    test();
    return 0;
}