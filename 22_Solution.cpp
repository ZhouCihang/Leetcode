#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution
{
public:
//如果左括号数量不大于 nn，我们可以放一个左括号。如果右括号数量小于左括号的数量，我们可以放一个右括号。
    vector<string> result;
    vector<string> generateParenthesis(int n)
    {
        string path = "";
        backtracking(path, 0, 0, n);
        return result;
    }
    void backtracking(string &path, int left, int right, int n)
    {
        if(path.size() == 2*n){
            result.push_back(path);
            return;
        }
        if(left < n){
            path.push_back('(');
            backtracking(path, left + 1, right, n);
            path.pop_back();
        }
        if(right < left){
            path.push_back(')');
            backtracking(path, left, right + 1, n);
            path.pop_back();
        }
    }
};

class SolutionOriginal {
    bool valid(const string& str) {
        int balance = 0;
        for (char c : str) {
            if (c == '(') {
                ++balance;
            } else {
                --balance;
            }
            if (balance < 0) {
                return false;
            }
        }
        return balance == 0;
    }

    void generate_all(string& current, int n, vector<string>& result) {
        if (n == current.size()) {
            if (valid(current)) {
                result.push_back(current);
            }
            return;
        }
        current += '(';
        generate_all(current, n, result);
        current.pop_back();
        current += ')';
        generate_all(current, n, result);
        current.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        generate_all(current, n * 2, result);
        return result;
    }
};


int main()
{
    Solution solution;
    vector<string> result;
    result = solution.generateParenthesis(3);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " " << endl;
    }
    return 0;
}