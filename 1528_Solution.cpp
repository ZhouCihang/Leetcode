#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string str = s;
        for (int i = 0; i < s.size(); i++){
            //str[indices[i]] = s[i];
            string ch = s[indices[i]];
            str.replace(i,1,ch);
            //cout <<s[indices[i]]<<endl;
        }
        return str;
    }
};

void test(){
    Solution sol;
    vector<int> indices {4,5,6,7,0,2,1,3};
    string rel = sol.restoreString("codeleet", indices);
    cout << rel << endl;
}

int main(){
    test();
    return 0;
}