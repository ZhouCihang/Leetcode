#include <iostream>
using namespace std;
#include <vector>
#include <stack>

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
    vector<int> postorderTraversalIterative(TreeNode *root)
    {
        vector<int> result;
        if(root == NULL) return result;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode *node = st.top();
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left);  
            if (node->right) st.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }
    void traversal(TreeNode *curr, vector<int> &res){
        if(curr == NULL) return;
        traversal(curr->left, res);
        traversal(curr->right, res);
        res.push_back(curr->val);
    }
};

int main()
{
    return 0;
}