#include <iostream>
using namespace std;
#include <vector>
#include <queue>

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    vector<vector<int> > levelOrder(Node *root)
    {
        vector<vector<int> > res;
        if (root == NULL)
            return res;

        queue<Node *> qu;
        qu.push(root);

        while (!qu.empty())
        {
            int curSize = qu.size();
            vector<int> temp;
            for (int i = 0; i < curSize; i++){
                Node * node = qu.front();
                qu.pop();
                temp.push_back(node->val);
                for(auto & n: node->children)
                    qu.push(n);
            }
            res.push_back(temp);
        }
        return res;
    }
};

int main()
{
    return 0;
}