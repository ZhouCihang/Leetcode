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

class solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traverse(root, result);
        return result;
    }
    void traverse(TreeNode *cur, vector<int> &vec)
    {
        if(cur == NULL) return;
        traverse(cur->left, vec);
        vec.push_back(cur->val);
        traverse(cur->right, vec);
    }
};

int main()
{
    return 0;
}