#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        stack<string> st;

        for(int i = 0; i < logs.size(); i++){
            if(logs[i] == "../"){
                if(!st.empty())
                    st.pop();
                else
                    continue;
            }else if(logs[i] == "./"){
                continue; 
            }else{
                st.push(logs[i]);
            }
        }
        return st.size();
    }
};

void test()
{
    Solution solution;
    vector<string> logs{"./","../","./"};
    cout << solution.minOperations(logs) << endl;
}

int main()
{
    test();
    return 0;
}