#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    string defangIPaddr(string address) {
        string result;
        for (int i = 0; i < address.size(); i++){
            if(address[i] == '.'){
                result += "[.]";
            }else{
                result += address[i];
            }
        }
        return result;
    }
};

void test(){
    Solution sol;
    string str = "1.1.1.1";
    string ip = sol.defangIPaddr(str);
    cout << ip << endl;
}

int main(){
    test();
    return 0;
}