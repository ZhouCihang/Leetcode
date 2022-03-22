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
        for (auto &nested : nestedList)
        {
            sum += getSum(nested, 1);
        }
        return sum;
    }
    int getSum(NestedInteger &nested, int depth)
    {
        int temp = 0;
        if (nested.isInteger())
        {
            return depth * nested.getInteger();
        }
        for (auto a : nested.getList())
        {
            temp += getSum(a, depth + 1);
        }
        return temp;
    }
};

int main()
{
    return 0;
}