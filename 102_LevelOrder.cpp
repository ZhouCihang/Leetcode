#include <iostream>
using namespace std;
#include <vector>
#include <queue>

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int> > levelOrderBFS(TreeNode *root)
    {
        vector <vector <int>> ret;
        if (!root) {
            return ret;
        }

        queue <TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int currentLevelSize = q.size();
            ret.push_back(vector <int> ());
            for (int i = 1; i <= currentLevelSize; ++i) {
                auto node = q.front(); q.pop();
                ret.back().push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return ret;
    }

    vector<vector<int> > levelOrderRecursive(TreeNode *root)
    {
        vector<vector<int> > result;
        traversal(root, result, 0);
        return result;
    }

    void traversal(TreeNode *root, vector<vector<int> > &result, int level)
    {
        if (root == NULL)
            return;
        if (level >= result.size())
        {
            result.push_back(vector<int>());
        }
        result[level].push_back(root->val);
        traversal(root->left, result, level + 1);
        traversal(root->right, result, level + 1);
    }
};

int main()
{
    return 0;
}