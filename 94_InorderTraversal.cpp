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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }
    void traversal(TreeNode *curr, vector<int> &res){
        if(curr == NULL) return;
        traversal(curr->left, res);
        res.push_back(curr->val);
        traversal(curr->right, res);
    }
};

int main()
{
    return 0;
}