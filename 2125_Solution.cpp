#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
#include <string>

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int ans = 0, prev = 0;
        for (string s : bank)
        {

            int temp = 0;
            for (int i = 0; i < s.size(); i++)
                if (s[i] == '1')
                    temp++;

            if (temp)
            {
                ans += prev * temp;
                prev = temp;
            }
        }
        return ans;
    }
};

int main()
{
    vector<string> bank{"011001", "000000", "010100", "001000"};
    Solution solution;
    cout << solution.numberOfBeams(bank) << endl;

    string str = "111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";
    cout << str.length() << endl;
    return 0;
}