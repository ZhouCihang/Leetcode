#include <iostream>
using namespace std;
#include <string>

class Solution
{
public:
    string reverseWords(string &inputString)
    {
        // detect space and remove duplicates spaces
        // reverse the string
        reverseString(inputString, 0, inputString.length() - 1);
        int j = 0;
        for (int i = 1; i < inputString.length(); ++i)
        {
            if (inputString[i] == ' ')
            {
                reverseString(inputString, j, i - 1);
                j = i + 1;
            }
        }
        reverseString(inputString, j, inputString.length() - 1);
        // reverse each word
        return inputString;
    }

    void reverseString(string &str, int startIndex, int endIndex)
    {
        while (startIndex < endIndex)
        {
            swap(str[startIndex++], str[endIndex--]);
        }
    }
};

int main()
{
    Solution solution;
    string str = "have a good day";
    cout << solution.reverseWords(str) << endl;
    return 0;
}