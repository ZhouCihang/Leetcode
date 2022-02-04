#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int val = 0;
        for(vector<string>::iterator it = operations.begin(); it != operations.end(); it++){
            if(*it == "--X" || *it == "X--"){
                val--;
            }
            if(*it == "++X" || *it == "X++"){
                val++;
            }
        }
        return val;
    }
};

void test(){
    vector<string> v;
    v.push_back("--X");
    v.push_back("X++");
    v.push_back("X++");
    
    Solution sol;
    int res = sol.finalValueAfterOperations(v);
    cout<<res<<endl;
}

int main()
{
    test();
    return 0;
}