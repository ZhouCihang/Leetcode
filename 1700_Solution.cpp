#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <queue>

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> qu;
        stack<int> st;

        for(int i = 0; i < students.size(); i++){
            qu.push(students[i]);
        }
        for(int i = sandwiches.size() -1; i >= 0; i--){
            st.push(sandwiches[i]);
        }

        for(int i = 0; i< qu.size(); i++){
            if(qu.front() ==  st.top()){
                st.pop();
                qu.pop();
                i = -1;
            }else{
                int temp = qu.front();
                qu.pop();
                qu.push(temp);
            }
        }

        return st.size();
    }
};

void test(){
    Solution s;
    vector<int> students {1,1,1,0,0,1};
    vector<int> sandwiches{1,0,0,0,1,1};

    cout << s.countStudents(students, sandwiches)<< endl;
}

int main(){
    test();
    return 0;
}