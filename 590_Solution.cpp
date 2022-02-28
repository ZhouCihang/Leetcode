#include <iostream>
using namespace std;
#include <vector>

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

    void postorder(Node *root, vector<int> &res){
        if (root == nullptr) return;
        for (int i = 0; i <root->children.size(); i++){
            postorder(root->children[i], res);
        }
        res.push_back(root->val);
    }
    vector<int> postorder(Node *root)
    {
        vector<int> res;
        postorder(root, res);
        return res;
    }

    void preorder(Node *root, vector<int> &res){
        if (root == nullptr) return;
        res.push_back(root->val);
        for (int i = 0; i <root->children.size(); i++){
            preorder(root->children[i], res);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};
