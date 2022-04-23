#include <iostream>
using namespace std;
#include <string>
#include <vector>

const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900, "CM"},
    {500, "D"},
    {400, "CD"},
    {100, "C"},
    {90, "XC"},
    {50, "L"},
    {40, "XL"},
    {10, "X"},
    {9, "IX"},
    {5, "V"},
    {4, "IV"},
    {1, "I"},
};

class Solution
{
public:
    string intToRoman(int num)
    {
        string result = "";
        for(auto &[value, symbol]:valueSymbols){
            while(num >= value){
                num -= value;
                result += symbol;
            }
            if(num == 0){
                break;
            }
        }
        return result;
    }
};

int main()
{
    Solution mySolution;
    cout << mySolution.intToRoman(1994) << endl;
    return 0;
}