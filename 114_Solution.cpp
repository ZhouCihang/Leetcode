#include <iostream>
using namespace std;
#include <vector>

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
    void flatten(TreeNode *root)
    {
        vector<TreeNode *> path;
        traverse(root, path);

        for (int i = 1; i < path.size(); ++i){
            TreeNode *prev = path[i-1], *curr = path[i];
            prev->left = NULL;
            prev->right = curr;
        }
    }
    void traverse(TreeNode *root, vector<TreeNode *> &path)
    {
        if (root == NULL)
            return;

        path.push_back(root);
        traverse(root->left, path);
        traverse(root->right, path);
    }
};

int main()
{
    Solution solution;
    TreeNode root(1);
    TreeNode lroot(2);
    TreeNode rroot(5);
    TreeNode llroot(3);
    TreeNode rrroot(4);
    TreeNode rrrroot(6);

    root.left = &lroot;
    root.right = &rroot;

    lroot.left = &llroot;
    lroot.right = &rrroot;

    rroot.right = &rrrroot;

    solution.flatten(&root);
    

    return 0;
}
