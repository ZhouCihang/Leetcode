#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    string interpret(string command) {

        int pos = 0;
        while((pos = command.find("()", pos)) != -1){
            command = command.replace(pos, 2, "o");
            pos += 1;
        }
        pos = 0;
        while((pos = command.find("G", pos)) != -1){
            command = command.replace(pos, 1, "G");
            pos += 1;
        }

        pos = 0;
        while((pos = command.find("(al)", pos)) != -1){
            command = command.replace(pos, 4, "al");
            pos += 2;
        }

        return command;
    }
};

void test(){
    Solution solution;
    string result = solution.interpret("G()(G)()()(al)");

    cout <<result <<endl;

}

int main(){
    test();
    return 0;
}