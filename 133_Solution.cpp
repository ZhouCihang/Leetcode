#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <unordered_map>

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    unordered_map<Node *, Node *> mp;

    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;

        unordered_map<Node *, Node *> visited;
        visited[node] = new Node(node->val);

        queue<Node *> qu;
        qu.push(node);

        while (!qu.empty())
        {
            Node *cur = qu.front();
            qu.pop();

            for (auto &neig : cur->neighbors)
            {
                if (visited.find(neig) == visited.end())
                {
                    visited[neig] = new Node(neig->val);
                    qu.push(neig);
                }
                visited[cur]->neighbors.push_back(visited[neig]);
            }
        }
        return visited[node];
    }
};

int main()
{
    return 0;
}