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
    int maxPathSum(TreeNode *root)
    {
        int sum = root->val;
        dfs(root, sum);
        return sum;
    }

    int dfs(TreeNode *root, int &sum){
        if(root == NULL) return 0;
        int left = max(dfs(root->left, sum),0);
        int right = max(dfs(root->right, sum),0);
        
        sum = max(sum, root->val + left + right);
        return root->val + max(left, right);
    }
};
int main()
{
    return 0;
}