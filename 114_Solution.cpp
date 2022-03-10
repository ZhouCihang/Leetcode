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
        TreeNode *pt = root;
        traverse(root, pt);
    }
    void traverse(TreeNode *pt, TreeNode *root)
    {
        if (root == NULL)
            return;

        pt->right = root;
        traverse(root->left, pt);
        traverse(root->right, pt);
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
