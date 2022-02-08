#include <iostream>
using namespace std;
#include <stack>

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> c;
        string result;

        for (int i = 0; i < s.length(); i++){
            if(s[i] == '('){
                if(c.size() > 0){
                    result +="(";
                }
                c.push('(');
            }
            else{
                if(c.size() > 1){
                    result += ')';
                }
                c.pop();
            }
        }
        return result;
    }
};

void test(){
    Solution solution;
    cout << solution.removeOuterParentheses("(()())(())") << endl;
}

int main(){
    test();
    return 0;
}