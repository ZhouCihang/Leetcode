#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
    string removeDuplicates(string s)
    {
        stack<int> st;
        string res = "";

        for (int i = 0; i < s.length(); i++)
        {
            if (!st.empty() && s[i] == s[st.top()])
            {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }

        while (!st.empty())
        {
            res += s[st.top()];
            st.pop();
        }
        reverse(res.begin(),res.end());

        return res;
    }
};

void test()
{
    Solution s;
    string res = s.removeDuplicates("azxxzy");
    cout << res << endl;
}

int main()
{
    test();
    return 0;
}