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
    vector<int> tree;
    bool isValidBST(TreeNode *root)
    {
        if(root == NULL) return true;
        
        dfs(root);
        for(int i = 1; i < tree.size();i++){
            if(tree[i] <= tree[i-1]) return false;
        }
        return true;
    }

    void dfs(TreeNode *root)
    {
        if(root == NULL) return;

        dfs(root->left);
        tree.push_back(root->val);
        dfs(root->right);
    }
};

int main()
{
    return 0;
}