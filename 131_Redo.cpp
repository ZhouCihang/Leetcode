#include <iostream>
using namespace std;
#include <vector>
#include <string>

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
        if(index == s.length()){
            result.push_back(path);
            return;
        }
        for(int i = index; i <= s.length(); i++){
            if(isPalindrome(s, index, i)){
                path.push_back(s.substr(index, i - index + 1));
                backtracking(s, path, i+1);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int left, int right){
        while(left <= right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
};