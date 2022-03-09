#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
#include <algorithm>

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
    unordered_map<TreeNode *, pair<int, int>> Tmap;
    double maximumAverageSubtree(TreeNode *root)
    {
        double res = -1;
        traversal(root, res);
        return res;
    }
    pair<int, int> traversal(TreeNode *root, double &res)
    {
        if(root == NULL) return {0, 0};
        if(Tmap.count(root)) return Tmap[root];

        pair<int, int> left = traversal(root->left, res);
        pair<int, int> right = traversal(root->right, res);
        pair<int, int> curr;
        curr.first = left.first + right.first + root->val;
        curr.second = left.second + right.second + 1;
        res = max(res, (double)curr.first / curr.second);
        Tmap[root] = curr;
        return curr;
    }
};

int main()
{
    Solution solution;
    TreeNode root(5);
    TreeNode lroot(6);
    TreeNode rroot(1);

    root.left = &lroot;
    root.right = &rroot;

    cout<<solution.maximumAverageSubtree(&root)<<endl;
    return 0;
}