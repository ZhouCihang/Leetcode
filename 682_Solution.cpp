#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        int result = 0;
        stack<int> st;

        for (int i = 0; i < ops.size(); i++)
        {
            if(ops[i] == "C"){
                st.pop();
            }else if(ops[i] == "D"){
                st.push(2*st.top());
            }else if(ops[i] == "+"){
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.push(temp1);
                st.push(temp1+temp2);
            }else{
                st.push(stoi(ops[i]));
            }
        }
        
        while (!st.empty()){
            result += st.top();
            st.pop();
        }
        return result;
    }
};

void test()
{
    Solution solution;
    vector<string> ops{"5", "2", "C", "D", "+"};
    cout << solution.calPoints(ops) << endl;
}

int main()
{
    test();
    return 0;
}