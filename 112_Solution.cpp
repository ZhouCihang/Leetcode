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
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
            return false;

        queue<TreeNode *> qNode;
        qNode.push(root);
        queue<int> qVal;
        qVal.push(root->val);
        while (qNode.size() != 0)
        {
            TreeNode *node = qNode.front();
            qNode.pop();
            int temp = qVal.front();
            qVal.pop();

            if (node->left == NULL && node->right == NULL)
            {
                if (temp == targetSum)
                    return true;
                continue;
            }
            if(node->left != NULL){
                qNode.push(node->left);
                qVal.push(temp + node->left->val);
            }
            if(node->right != NULL){
                qNode.push(node->right);
                qVal.push(temp + node->right->val);
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}