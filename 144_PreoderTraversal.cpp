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
    vector<int> preorderTraversalIterative(TreeNode *root)
    {
        vector<int> result;
        if(root == NULL) return result;
        stack<TreeNode *> st;
        st.push(root);
        while(!st.empty()){
            TreeNode * node = st.top();
            st.pop();
            result.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return result;
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traveral(root, result);
        return result;
    }

    void traveral(TreeNode *curr, vector<int> &res)
    {
        if (curr == NULL)
            return;
        res.push_back(curr->val);   //mid
        traveral(curr->left, res);  //left
        traveral(curr->right, res); //right
    }
};

int main()
{
    return 0;
}