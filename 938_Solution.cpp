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
    int rangeSumBST(TreeNode *root, int low, int high)
    {
        if (root == nullptr)
            return 0;
        if (root->val > high)
        {
            return rangeSumBST(root->left, low, high);
        }
        if (root->val < low)
        {
            return rangeSumBST(root->right, low, high);
        }
        return root->val + rangeSumBST(root->left, low, high) + rangeSumBST(root->right, low, high);
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr || root2 == nullptr){
            return root1 == nullptr ? root2 : root1;
        }
        return dfs(root1, root2);
    }
    TreeNode* dfs(TreeNode* root1, TreeNode* root2){
        if(root1 == nullptr || root2 == nullptr){
            return root1 == nullptr ? root2 : root1;
        }

        root1->val += root2->val;
        root1->left = dfs(root1->left, root2->left);
        root1->right = dfs(root1->right, root2->right);
        return root1;
    }

    void inorder(TreeNode* root, vector<int> &res){
        if(root == nullptr){
            return;
        }
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }

    TreeNode* increasingBST(TreeNode* root) {
        vector<int> res;
        inorder(root, res);

        TreeNode * dummyNode = new TreeNode(-1);
        TreeNode * currNode = dummyNode;
        
        for(int value:res){
            currNode->right = new TreeNode(value);
            currNode = currNode->right;
        }
        return dummyNode->right;
    }
};