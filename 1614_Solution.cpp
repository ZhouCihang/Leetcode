#include <iostream>
using namespace std;
#include <stack>
#include <algorithm>

class Solution {
public:
    int maxDepth(string s) {
        stack<char> c;
        int depth = 0;

        for(int i = 0; i <s.length(); i++){
            if(s[i] == '('){
                c.push(s[i]);
            }
            if(s[i] == ')'){
                int x = c.size();
                depth = max(depth, x);
                c.pop();
            }
        }
        return depth;
    }
};

void test(){
    Solution solution;
    string str = "(1+(2*3)+((8)/4))+1";
    int res = solution.maxDepth(str);
    cout << res << endl;
}

int main(){
    test();
    return 0;
}