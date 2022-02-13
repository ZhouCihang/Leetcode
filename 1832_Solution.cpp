#include <iostream>
using namespace std;
#include <unordered_set>

class Solution {
public:
    bool checkIfPangram(string s) {
        unordered_set<int> st;

        for(char c : s) {
            st.insert(c - 'a');
        }
        if(st.size()<26)
            return false;
        
        return true;

    }
};

int main(){
    Solution s;
    cout << s.checkIfPangram("thequickbrownfoxjumpsoverthelazydog") << endl;
    return 0;
}