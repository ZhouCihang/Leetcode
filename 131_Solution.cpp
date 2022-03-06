#include <iostream>
using namespace std;
#include <vector>

class Solution
{
public:
    vector<vector<string> > result;
    vector<vector<string> > partition(string s)
    {
        vector<string> path;
        backtracking(s, path, 0);
        return result;
    }
    void backtracking(string s, vector<string> &path, int index)
    {
        if (index == s.length())
        {
            result.push_back(path);
            return;
        }
        for (int i = index; i <= s.length(); i++)
        {
            if(isPalindrome(s, index, i)){
                cout << " substring is : " << s.substr(index, i - index + 1) <<endl;
                path.push_back(s.substr(index, i - index + 1));
                backtracking(s, path, i + 1);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int left, int right)
    {
        while (left <= right)
        {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<vector<string> > result;
    result = solution.partition("aab");
    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}