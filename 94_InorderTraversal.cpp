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

    vector<int> inorderTraversalUnion(TreeNode *root)
    {
        vector<int> result;
        stack<TreeNode *> st;
        if(root != NULL) st.push(root);

        while(!st.empty()){
            TreeNode *node = st.top();
            if(node != NULL){
                st.pop();
                if(node ->right) st.push(node->right);

                st.push(node);
                st.push(NULL);
                if(node->left) st.push(node->left);
            }else{
                st.pop();
                node = st.top();
                st.pop();
                result.push_back(node->val);
            }
        }
        return result;
    }

    vector<int> inorderTraversalIterative(TreeNode *root)
    {
        vector<int> result;
        if (root == NULL)
            return result;
        stack<TreeNode *> st;
        TreeNode *curr = root;
        while (!st.empty() || curr != NULL)
        {
            if (curr != NULL) // 指针来访问节点，访问到最底层
            {
                st.push(curr);     // 将访问的节点放进栈
                curr = curr->left; // 左
            }
            else
            {
                curr = st.top(); // 从栈里弹出的数据，就是要处理的数据（放进result数组里的数据）
                st.pop();
                result.push_back(curr->val); // 中
                curr = curr->right;          // 右
            }
        }
        return result;
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traversal(root, result);
        return result;
    }
    void traversal(TreeNode *curr, vector<int> &res)
    {
        if (curr == NULL)
            return;
        traversal(curr->left, res);
        res.push_back(curr->val);
        traversal(curr->right, res);
    }
};

int main()
{
    return 0;
}