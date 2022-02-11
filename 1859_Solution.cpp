#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
public:
    string sortSentence(string s) {
        vector<string> words(9);
        string tmp = "";
        int n = 0;

        for(auto c:s){
            if(c >= '0' && c <= '9'){
                words[c - '0' - 1] = tmp;
                tmp.clear();
                n++;
            }else if(c != ' '){
                tmp.push_back(c);
            }
        }

        string result = words[0];
        for(int i = 1; i < n; ++i){
            result += " " + words[i];
        }

        return result;
    }
};

void test(){
    Solution solution;
    cout << solution.sortSentence("is2 sentence4 This1 a3") << endl;
}

int main(){
    test();
    return 0;
}