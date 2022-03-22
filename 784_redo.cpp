#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution
{
public:
    vector<string> result;
    vector<string> letterCasePermutation(string s)
    {
        string path;
        backtracking(path, s, 0);
        return result;
    }
    void backtracking(string &path, string &s, int index)
    {
        if (path.length() >= s.length())
        {
            result.push_back(path);
            return;
        }
        for (int i = index; i < s.size(); i++)
        {
            if (isdigit(s[i]))
            {
                path.push_back(s[i]);
                backtracking(path, s, i + 1);
            }
            else{
                if((s[i] >= 'A' && s[i] <= 'Z')||(s[i] >= 'a' && s[i] <= 'z')){
                    path.push_back(s[i]);
                    backtracking(path, s, i + 1);
                    path.pop_back();

                    s[i] ^= (1<<5);
                    path.push_back(s[i]);
                    backtracking(path, s, i + 1);
                }
            }
            path.pop_back();
        }
    }
};

int main()
{
    vector<string> result;
    Solution s;
    result = s.letterCasePermutation("a1b2");
    for(int i = 0; i < result.size(); i++){
        cout<< result[i] << " ";
    }
    cout << endl;
    return 0;
}