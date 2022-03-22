#include <iostream>
using namespace std;
#include <vector>

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class Solution
{
public:
    
    int depthSum(vector<NestedInteger> &nestedList)
    {
        int sum = 0;
        vector<vector<int> > result;

        for (auto &nested : nestedList)
        {
            dfs(result, nested, 0);
        }
        for(int i = result.size() - 1; i >= 0; --i){
            for(int j = 0; j < result[i].size(); ++j){
                sum += result[i][j] * (result.size()-i);
            }
        }

        return sum;
    }
    void dfs(vector<vector<int> > &result, NestedInteger &nested, int depth)
    {
        vector<int> path;
        if(depth < result.size()) path = result[depth];
        else result.push_back(path);

        if(nested.isInteger()){
            path.push_back(nested.getInteger());
            result[depth] = path;
        } else {
            for(auto a : nested.getList()){
                dfs(result, a, depth + 1);
            }
        }

    }
};

int main()
{
    return 0;
}