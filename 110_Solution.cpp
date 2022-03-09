#include <iostream>
using namespace std;
#include <vector>

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
    bool isBalanced(TreeNode *root)
    {
        return dfs(root) != -1;
    }
    int dfs(TreeNode *root)
    {
        if(root == NULL) return 0;
        int left = dfs(root->left);
        if(left == -1) return -1;
        int right = dfs(root->right);
        if(right == -1) return -1;

        if(abs(left - right) <2)
            return max(left, right) + 1;
        else
            return -1;
    }
};

int main()
{
    Solution solution;
    TreeNode root(1);
    TreeNode lroot(2);
    TreeNode rroot(2);
    TreeNode llroot(3);
    TreeNode rrroot(3);
    TreeNode lllroot(4);
    TreeNode rrrroot(4);

    root.left = &lroot;
    root.right = &rroot;
    lroot.left = &llroot;
    lroot.right = &rrroot;
    llroot.left = &lllroot;
    llroot.right = &rrrroot;

    cout <<solution.isBalanced(&root);

    return 0;
}