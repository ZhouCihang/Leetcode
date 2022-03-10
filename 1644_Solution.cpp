#include <iostream>
using namespace std;
#include <vector>

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        pair<TreeNode *, int> res = dfs(root, p, q);
        if (res.second < 2)
        {
            return NULL;
        }
        return res.first;
    }
    pair<TreeNode *, int> dfs(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == NULL)
            return {NULL, 0};

        pair<TreeNode *, int> left = dfs(root->left, p, q);
        pair<TreeNode *, int> right = dfs(root->right, p, q);

        if (root->val == p->val || root->val == q->val)
        {
            return {root, 1 + left.second + right.second};
        }

        if (left.first != NULL && right.first != NULL)
            return {root, 2};

        if (left.first != NULL)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
};

int main()
{
    return 0;
}