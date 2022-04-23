#include <iostream>
using namespace std;
#include <stack>

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for(auto &c:s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }else{
                if(st.empty() or (st.top()=='(' and c!=')') or (st.top()=='{' and c!='}') or (st.top()=='[' and c!=']')) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main()
{
    Solution solution;
    cout << solution.isValid("()[]{}") << endl;
    cout << solution.isValid("([{}])") << endl;
    
    return 0;
}