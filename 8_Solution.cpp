#include <iostream>
using namespace std;
#include <string>
#include <math.h>

class Solution
{
public:
    int myAtoi(string s)
    {
        //1. remove leading space
        string removeSpaceStr = trim(s);
        //2. read sign
        int sign = 1;
        int index = 0;
        if (removeSpaceStr[0] == '-')
        {
            sign = -1;
            index++;
        }
        if (removeSpaceStr[0] == '+')
        {
            sign = 1;
            index++;
        }

        double result = 0;
        while (isdigit(removeSpaceStr[index]))
        {
            result = result * 10 + (removeSpaceStr[index] - '0');
            index++;
        }

        result = result * sign;
        if (result > (pow(2, 31) - 1))
            return pow(2, 31) - 1;
        if (result < (-1.0 * pow(2, 31)))
            return -1.0 * pow(2, 31);

        return result;
    }
    string trim(string &str)
    {
        const auto strBegin = str.find_first_not_of(" ");
        if (strBegin == string::npos)
            return ""; // no content

        const auto strEnd = str.find_last_not_of(" ");
        const auto strRange = strEnd - strBegin + 1;

        return str.substr(strBegin, strRange);
    }
};

int main()
{
    Solution mySolution;
    cout << mySolution.myAtoi("   -4296") << endl;
    return 0;
}