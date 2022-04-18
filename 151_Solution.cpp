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
        removeSpaces(inputString);
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

    void removeSpaces(string &str)
    {
        int slow = 0, fast = 0;
        while (fast < str.length() && str[fast] == ' ')
            ++fast;
        while (fast < str.length())
        {
            if (fast > 0 && str[fast] == str[fast - 1] && str[fast] == ' ')
            {
                ++fast;
            }
            else
            {
                str[slow++] = str[fast++];
            }
        }
        if (slow > 1 && str[slow - 1] == ' ')
        {
            str.resize(slow - 1);
        }
        else{
            str.resize(slow);
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