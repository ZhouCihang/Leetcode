#include <iostream>
using namespace std;
#include <stack>

class Solution {
public:
    string makeGood(string s) {
        stack<int> st;

        for(int i = 0; i < s.length(); i++){
            // while(!st.empty() && tolower(s[st.top()]) == tolower(s[i]) && s[st.top()] != s[i]){
            //     st.pop();
            //     i++;
            // }
            // st.push(i);
            if(!st.empty() && tolower(s[st.top()]) == tolower(s[i]) && s[st.top()] != s[i]){
                st.pop();
            }else{
                st.push(i);
            }
        }

        string str = "";
        while(!st.empty()){
            str+=s[st.top()];
            st.pop();
        }
        reverse(str.begin(), str.end());

        return str;
    }
};

void test(){
    Solution s;
    cout << s.makeGood("leEeetcode") << endl;
}

int main(){
    test();
    return 0;
}