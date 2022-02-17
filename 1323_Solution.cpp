#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    int maximum69Number(int num)
    {
        string s = to_string(num);
        for (char& ch: s) {
            if (ch == '6') {
                ch = '9';
                break;
            }
        }
        return stoi(s);

    }
};

void test(){
    Solution solution;
    cout << solution.maximum69Number(9669) << endl;
}

int main()
{
    test();
    return 0;
}