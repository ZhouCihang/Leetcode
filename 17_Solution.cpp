#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<string> result;
    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};
        string path = "";
        vector<string> letters{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtracking(letters, path, digits, 0);
        return result;
    }
    void backtracking(vector<string> letters, string path, string digits, int index){
        if(index == digits.length()){
            result.push_back(path);
            return;
        }

        for(auto &c:letters[digits[index] - '0']){
            path.push_back(c);
            backtracking(letters, path, digits, index + 1);
            path.pop_back();
        }
    }
};

int main(){
    vector<string> letter;
    Solution s;
    letter = s.letterCombinations("49");
    for(int i = 0; i < letter.size(); i++){
        cout << letter[i] << " ";
    }
    cout << endl;
    return 0;
}